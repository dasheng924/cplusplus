#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <pthread.h>


int main(void) {
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
    tmp = readset;//每循环一次都初始化一次这个原始的集合
    int ret = select(maxfd + 1, &tmp, NULL, NULL, NULL);
    //判断监听的fd在不在集合里面，在的话就要去和客户端建立连接
    if (FD_ISSET(sfd, &tmp)) {
        printf("ininin\n");
      // accept
      int cfd = accept(sfd, NULL, NULL);
      FD_SET(cfd, &readset);  //把通信的fd加入到读集合的监听里面；
      //为了防止加入到已经被修改的集合里面，上面加入监听文件描述符的时候，就加入了tmp，临时的集合里面
      maxfd = cfd > maxfd? cfd: maxfd;  //修改最大文件描述符，保证底层线性表遍历的准确性
    }
    printf("out\n");
    //当处理完通信的文件描述符之后，开始进行通信
    for(int i = 0; i < maxfd+1;++i) { 
        printf("in_%d\n",i); //遍历寻找，那个文件描述符是通信的文件描述符
      if (i != sfd && FD_ISSET(i, &tmp)) {
        //接受数据
        // recv send
        printf("get\n");
        char recv_buf[1024];
        bzero(recv_buf, sizeof(recv_buf));

        int len = recv(i, recv_buf, sizeof(recv_buf), 0);
        if (len > 0) {
            puts(recv_buf);

          for (int i = 0; i < len; ++i) {
            recv_buf[i] = toupper(recv_buf[i]);
          }

          send(i, recv_buf, len, 0);
  
        } else if (len == 0) {
          perror("other closed for connect!");
          FD_CLR(i, &readset);
          close(i);
          break;
        } else {
          printf("error!");
          break;
        }

      }
    }
  }

  close(sfd);

  return 0;
}