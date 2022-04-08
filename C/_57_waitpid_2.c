//waitpid :1.可以指定回收的方式是阻塞的还是非阻塞的
//2.可以指定某一个进程或者某一个进程组

/*
waitpid 这个是可以设置为非阻塞的
waitpid 这个函数可以判断出来子进程的状态，返回值 > 0 表示回收了的子进程

返回值 == 0 表示这个子进程还在运行，还没有退出

返回值其他值是  异常状态，或者没有子进程了    




*/




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    for(int i = 0;i<5;++i)
    {
        pid = fork();
        if(pid==0)
        {
            break;
        }
    }
    if(pid > 0)
    {
        while(1)
        {
            int status;
            pid_t ret = waitpid(-1,&status,WNOHANG); //非阻塞
            if(ret > 0)
            {
                if(WIFEXITED(status))
                    printf("子进程正常退出，退出的状态码是%d\n",WEXITSTATUS(status));
                if(WIFSIGNALED(status))
                    printf("子进程是被信号终止的，终止的信号是%d\n",WTERMSIG(status));
            }
            else if(ret == 0)
            {
                printf("子进程正在运行,还没有退出，不做任何处理...\n");
            }
            else{
                printf("子进程的状态异常！\n");
                break;
            }
        }
        printf("我是父进程，我的ID是%d\n",getpid());

    }
    else if(pid == 0)
    {
        printf("我是子进程，我的ID是%d,我父进程的ID是%d\n",getpid(),getppid()) ;
    }
    else{
        perror("fork  fail!");
    }


    exit(0);
}