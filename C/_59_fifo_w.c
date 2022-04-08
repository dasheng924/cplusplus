//有名管道进行写操作
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    //创建有名管道
    int ret = mkfifo("./fifotest",0664);
    if(ret == -1)
    {
        perror("mkfifo error!");
        exit(-1);
    }
    printf("管道文件创建成功！\n");

    int ret_open = open("./fifotest",O_WRONLY);
    if(ret_open == -1)
    {
        perror("open fifo fail!");
        exit(-1);
    }

    //循环写入文件
    int i = 0;
    while(i<100)
    {
        char buf[4096]={0};
        sprintf(buf,"hello world %d",i+1);
        write(ret_open,buf,strlen(buf)); //如果只有写端，没有读端会阻塞的
        i++;
        sleep(1);
    }
    close(ret_open);
    exit(0);
}



/*
设置为非阻塞的形式
// 通过fcntl 修改就可以, 一般情况下不建议修改
// 管道操作对应两个文件描述符, 分别是管道的读端 和 写端

// 1. 获取读端的文件描述符的flag属性
int flag = fcntl(fd[0], F_GETFL);
// 2. 添加非阻塞属性到 flag中
flag |= O_NONBLOCK;
// 3. 将新的flag属性设置给读端的文件描述符
fcntl(fd[0], F_SETFL, flag);
// 4. 非阻塞读管道
char buf[4096];
read(fd[0], buf, sizeof(buf));

*/