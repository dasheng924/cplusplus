#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

    pid_t pid = fork();
    if(pid == 0)
    {
        printf("我是子进程，我的ID是%d,父进程的ID是%d\n",getpid(),getppid());
        sleep(1); //子进程睡眠1s，保证父进程先退出，形成孤儿进程
    }
    else if(pid > 0)
    {
        printf("我是父进程，ID是%d\n",getpid());
    }
    else{
        perror("fork error!");
    }



/*
最终子进程的父进程ID是1，表明这个进程成为了孤儿进程，被init进程领养了
init 进程释放了子进程内核区的PCB资源
我是父进程，ID是55360
我是子进程，我的ID是55361,父进程的ID是1

*/

    exit(0);
}