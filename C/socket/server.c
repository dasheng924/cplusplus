#include "library.h"
#include <stdio.h>

int main(void)
{   
    //创建套接字
    int fd = createSocket();

    //bind
    bindSocket(fd,8888);
    //listen
    setListen(fd);
    //accept
    struct sockaddr_in caddr;
    int cfd = acceptConn(fd,&caddr);
    if(cfd > 0)
        printf("okok!\n");



    char r_buf[1024];
    bzero(r_buf,sizeof(r_buf));

    recv(cfd,r_buf,sizeof(r_buf),0);
    puts(r_buf);


    char * buf = malloc(128);
    recvMsg(cfd,&buf);
    puts(r_buf);

    free(buf);
    


    closeSocket(cfd);
    closeSocket(fd);


    exit(0);
}