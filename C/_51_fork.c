#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{

    pid_t pid = fork();
    if(pid > 0)
    {
        printf("parent :子进程的ID%d\n",getpid()) ;
    }
    else if (pid == 0)
    {
        /* code */
        printf("children :父进程的ID：%d，子进程的ID：%d\n",getppid(),getpid()) ;
    }
    else{
        printf("创建自进程失败！\n") ;
    }

    //父子进程都会执行
    for(int i = 0;i<5;++i)
    {
        printf("%d\n",i) ;
    }
    
    printf("hello world\n")  ;
    return  0;
}