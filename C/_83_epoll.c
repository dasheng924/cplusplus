#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>


int main(void)
{
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
  ret = listen(sfd,10);
  if (ret == -1) {
    perror("listen error");
    return -1;
  }


    //创建epoll实例
    int epfd = epoll_create(1);
    if(epfd == -1)
    {
        perror("create epoll fail!");
        exit(-1);
    }

    //要把sfd加入到epfd 树上

    struct epoll_event ev;
    ev.event = EPOLLIN;
    ev.data.fd = sfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&ev);

    //然后开始循环检测
    struct epoll_event evs[1024];
    int size = sizeof(evs)/sizeof(evs[0]);


    while(1)
    {
        //调用一次，就检测一次
        int num = epoll_wait(epfd,evs,size,-1);
        printf("num = %d\n",num);

        for(int i = 0;i<num;++i)
        {
            if(     )



        }









    }








  // accept
  struct sockaddr_in caddr;
  socklen_t caddr_len = sizeof(caddr);

  int cfd = accept(sfd, (struct sockaddr*)&caddr, &caddr_len);
  if (cfd == -1) {
    perror("accept error");
    return -1;
  }
  fputs("waiting client connect.....",stdout);
  // get client info
  char ip[32];
  bzero(ip, sizeof(ip));
  int port = 0;
  inet_ntop(AF_INET, &caddr.sin_addr.s_addr, ip, sizeof(ip));
  port = caddr.sin_port;

  printf("client_info:%s:%d\n",ip, port);

  // recv send
  char recv_buf[1024];
  char send_buf[1024];
  bzero(recv_buf, sizeof(recv_buf));
  bzero(send_buf, sizeof(send_buf));
  while (1) {
    int len = recv(cfd, recv_buf, sizeof(recv_buf), 0);
    if (len > 0) {
      fputs(recv_buf,stdout);
      send(cfd, recv_buf, len, 0);
    } else if (len == 0) {
      perror("error in connect!");
      break;
    } else {
      printf("error!");
      break;
    }
 
  }
  close(sfd);
  close(cfd);


  return 0;
}