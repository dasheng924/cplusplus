#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <pthread.h>

//线程的参数
typedef struct fdinfo{
    int fd;
    int *maxfd;
    fd_set *fdset;
}FDINFO;

pthread_mutex_t mutex;

void *acceptConn(void *arg)
{
    printf("acceptConn->%ld\n",pthread_self());
    FDINFO *fdinfo = (FDINFO*)arg;

    int cfd = accept(fdinfo->fd, NULL, NULL);
    pthread_mutex_lock(&mutex);
    FD_SET(cfd, fdinfo->fdset);  //把通信的fd加入到读集合的监听里面；
    //为了防止加入到已经被修改的集合里面，上面加入监听文件描述符的时候，就加入了tmp，临时的集合里面
    int max  = *fdinfo->maxfd;
    *(fdinfo->maxfd) = max>cfd?max:cfd;  //修改最大文件描述符，保证底层线性表遍历的准确性
    pthread_mutex_unlock(&mutex);
    free(fdinfo);
    pthread_exit(NULL);
}

void *communicate(void *arg) {
  printf("communicate->%ld\n",pthread_self());
  FDINFO *info = (FDINFO *)arg;

  char recv_buf[1024];
  bzero(recv_buf, sizeof(recv_buf));

  int len = recv(info->fd, recv_buf, sizeof(recv_buf), 0);
  if (len > 0) {
    puts(recv_buf);

    for (int i = 0; i < len; ++i) {
      recv_buf[i] = toupper(recv_buf[i]);
    }

    send(info->fd, recv_buf, len, 0);

  } else if (len == 0) {
    perror("other closed for connect!");
    pthread_mutex_lock(&mutex);
    FD_CLR(info->fd, info->fdset);
    pthread_mutex_unlock(&mutex);
    close(info->fd);
    pthread_exit(NULL);
  } else {
    printf("error!");
    free(info);
    pthread_exit(NULL);
  }
  free(info);
  pthread_exit(NULL);
}

int main(void) {

    pthread_mutex_init(&mutex,NULL);

  // 1.先创建套接字
  int sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd == -1) {
    perror("socket error!");
    return -1;
  }

  // bind
  struct sockaddr_in saddr;
  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(8888);
  saddr.sin_addr.s_addr = INADDR_ANY;
  int ret = bind(sfd, (struct sockaddr*)&saddr, sizeof(saddr));
  if (ret == -1) {
    perror("bind error!");
    return -1;
  }

  // listen
  printf("listen ---\n");
  ret = listen(sfd, 10);
  if (ret == -1) {
    perror("listen error");
    return -1;
  }

  fd_set readset;
  fd_set tmp;
  
  FD_ZERO(&readset);
  FD_ZERO(&tmp);
  FD_SET(sfd, &readset);  //检测的fd 放入集合

  int maxfd = sfd;

  while (1) {
    pthread_mutex_lock(&mutex);
    tmp = readset;//每循环一次都初始化一次这个原始的集合
    pthread_mutex_unlock(&mutex);
    int ret = select(maxfd + 1, &tmp, NULL, NULL, NULL);
    //判断监听的fd在不在集合里面，在的话就要去和客户端建立连接
    if (FD_ISSET(sfd, &tmp)) {
      // accept
      pthread_t tid;
      FDINFO *fdinfo = (FDINFO*)malloc(sizeof(FDINFO));

      fdinfo->fd = sfd;
      fdinfo->fdset = &readset;
      fdinfo->maxfd = &maxfd;
      pthread_create(&tid,NULL,acceptConn,fdinfo);
      pthread_detach(tid);
     
    }
    //当处理完通信的文件描述符之后，开始进行通信
    for(int i = 0; i < maxfd+1;++i) { 
        printf("in_%d\n",i); //遍历寻找，那个文件描述符是通信的文件描述符
      if (i != sfd && FD_ISSET(i, &tmp)) {
        //接受数据
        // recv send

        FDINFO *info = (FDINFO*)malloc(sizeof(FDINFO));
        info->fd = i;
        info->fdset = &readset;
        info->maxfd = NULL;

        pthread_t tid2;
        pthread_create(&tid2,NULL,communicate,info);
        pthread_detach(tid2);      

      }
    }
  }

    pthread_mutex_destroy(&mutex);
  close(sfd);

  return 0;
}