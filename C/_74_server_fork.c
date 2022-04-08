#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>


//信号处理函数,父进程调用来回收子进程
void callback(int num)
{
    while(1)
    {
        pid_t pid = waitpid(-1,NULL,WNOHANG);
        if(pid <=0 )
        {
            printf("子进程正在运行，或者子进程被回收掉了!\n");
            break;
        }
        printf("child die,pid = %d\n",pid);
    }
}

int childWork(int fd);

int main()
{
    int s_fd = socket(AF_INET,SOCK_STREAM,0) ;
    if(s_fd == -1)
    {
        perror("socket erroe!");
        return -1;
    }

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr = INADDR_ANY;

    int num1 = 1;
    int ret = setsockopt(s_fd,SOL_SOCKET,SO_REUSEADDR,&num1,sizeof(num1));
    if(ret ==-1)
    {
        perror("setsockopt error!");
        return -1;
    }
    ret = bind(s_fd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ret == -1)
    {
        perror("bind error!");
        return -1;
    }

    ret = listen(s_fd,128);
    if(ret == -1)
    {
        perror("listen error!");
        return -1;
    }

   


    //信号捕捉函数的注册
    struct sigaction act;
    act.sa_flags = 0;
    act.sa_handler = callback;
    sigemptyset(&act.sa_mask);
    sigaction(SIGCHLD,&act,NULL);

    printf("准备连接中.....\n");


    //接受多个客户端的连接
    while(1)
    {
        struct sockaddr_in caddr;
        socklen_t len = sizeof(caddr);
        int c_fd = accept(s_fd,(struct sockaddr*)&caddr,&len);
        if(c_fd == -1)
        {
            if(errno == EINTR)
            {
                //accept 调用被信号打断，解除阻塞，重新调用
                continue;
            }
            perror("accept error!");
            exit(0);
        }

        sleep(4);
        char ip[24] = {0};
        printf("客户端的地址:%s,端口:%d\n",inet_ntop(AF_INET,&caddr.sin_addr.s_addr,ip,sizeof(ip)),ntohs(caddr.sin_port));

        //新的连接已经建立，创建子进程，用于通信
        pid_t pid = fork();
        if(pid == 0)
        {
            //子进程，进行通信
            //通信的文件描述符被拷贝到子进程的内核中
            //子进程不负责监听
            close(s_fd);
            while(1)
            {
                printf("客户端的地址:%s,端口:%d\n",inet_ntop(AF_INET,&caddr.sin_addr.s_addr,ip,sizeof(ip)),ntohs(caddr.sin_port));
                int ret = childWork(c_fd);
                if(ret <=0 )
                {
                    break;
                }
            }

            //退出子进程
            close(c_fd);
            exit(0);
        }
        else if(pid >0)
        {
            close(c_fd);
        }


    }

    exit(0);
}



int childWork(int fd)
{
    char r_buf[1024];
    bzero(r_buf,sizeof(r_buf));

    int len = recv(fd,r_buf,sizeof(r_buf),0);
    int count = 0;
    if(len >0)
    {
        printf("client say:%s\n",r_buf);
        write(fd,r_buf,len);
    }
    else if(len ==0)
    {
        printf("客户端已经断开连接了...\n");
    }
    else{
        perror("read error!");
    }
    return len;

}