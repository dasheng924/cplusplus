#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

struct SockInfo
{
    struct sockaddr_in addr;
    int fd;
    pthread_t tid;
} ;

struct SockInfo sockinfo[1024];

void *work(void *arg);

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

    //初始化SockInfo 数组
    int len =sizeof(sockinfo) /sizeof(sockinfo[0]);
    for(int i = 0;i< len;++i)
    {
        bzero(sockinfo,sizeof(sockinfo)) ;
        sockinfo[i].fd = -1;
        sockinfo[i].tid = (pthread_t)-1;
    }

    //accept
    struct SockInfo * pInfo ;
    while(1)
    {
        //找出可用的文件描述符
        for(int i = 0;i<len;++i)
        {
            if(sockinfo[i].fd == -1)
            {
                pInfo = &sockinfo[i];
                break;//找到就退出
            }
        }
        socklen_t sockLen = sizeof(struct sockaddr);
        int cfd = accept(sfd,(struct sockaddr*)&pInfo->addr,&sockLen);
        pInfo->fd = cfd;
        if(cfd == -1)
        {
            perror("accept error!");
            return -1;
        }

        pthread_t tid ;
        pthread_create(&tid,NULL,work,pInfo) ;
        pthread_detach(tid) ;
    }
    close(sfd);
    pthread_exit(NULL);
}

void *work(void *arg)
{
    if(arg == NULL)
    {
        perror("work error");
        return NULL;
    }
    struct SockInfo * pinfo = (struct SockInfo*)arg;
    int port = ntohs(pinfo->addr.sin_port );
    char ip[32];
    inet_ntop(AF_INET,&pinfo->addr.sin_addr.s_addr,ip,sizeof(ip));

    printf("client-->%s:%d\n",ip,port);

    char recv_buf[1024] = {0};
    char send_buf[1024]  = {0};
    // bzero(recv_buf,sizeof(recv_buf));
    // bzero(send_buf,sizeof(send_buf);
    while(1)
    {
        int len = recv(pinfo->fd,recv_buf,sizeof(recv_buf),0);
        if(len > 0)
        {
            fputs(recv_buf,stdout);
            send(pinfo->fd,recv_buf,len,0);
        }
        else if(len == 0)
        {
            perror("connect error!");
            break;
        }
        else{
            perror("error!");
            break;
        }
    }
    close(pinfo->fd) ;
    pinfo->fd = -1;

    pthread_exit(NULL);
}




140.82.113.3 github.com
185.199.108.153 assets-cdn.github.com
199.232.69.194 github.global.ssl.fastly.net


140.82.114.4 github.com
199.232.69.194 github.global.ssl.fastly.net
