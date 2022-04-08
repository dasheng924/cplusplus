//waitpid :1.可以指定回收的方式是阻塞的还是非阻塞的
//2.可以指定某一个进程或者某一个进程组

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{

    pid_t pid ;
    for(int i = 0;i<5;++i)
    {
        pid = fork();
        if(pid == 0)
        {
            break;
        }
    }
    if(pid > 0)
    {
        while (1)
        {
            //循环回收子进程 
            int status;
            pid_t ret = waitpid(-1,&status,0); // == wait(NULL)
            if(ret > 0)
            {
                printf("回收子进程成功，子进程的ID是%d\n",ret);
                if(WIFEXITED(status))
                    printf("子进程退出时候的状态码%d\n",WEXITSTATUS(status));
                if(WIFSIGNALED(status))
                    printf("子进程是被这个信号杀死的%d\n",WTERMSIG(status));
            }
            else{
                printf("回收失败或者已经没有子进程了!\n");
                break;
            }
            printf("我是父进程，我的ID是%d\n",getpid());
        }
        
    }
    else if(pid==0){
        printf("我是子进程，我的ID是%d,我的父进程ID是%d\n",getpid(),getppid());
    }







    exit(0);
}