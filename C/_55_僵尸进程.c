//僵尸进程：子进程已经死亡，用户区的资源已经释放，这个子进程的父进程不去回收子进程内核区的PCB资源
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{   
    pid_t pid ;
    for(int i = 0;i<5;++i)
    {
        pid = fork();
        if(pid == 0)
            break;
    }

    if(pid > 0 )
    {
        while (1)
        {
            sleep(1);
            //一次wait的调用 只能回收一个子进程，多次回收，需要循环调用
            pid_t ret = wait(NULL);//这个函数是阻塞的，检测到子进程退出，才会解除阻塞，回收资源
            if(ret > 0)
            {
                printf("回收子进程成功，子进程的ID是%d\n",ret);
            }
            else{
                printf("回收子进程失败...\n");
                break;
            }
            printf("我是父进程，我的ID是%d,我一直在循环，我不退出！\n",getpid());
            
        }

    }
    else if(pid== 0){
        printf("我是子进程，我的ID是%d,我的父进程的ID是%d\n",getpid(),getppid());
    
    }

    



    exit(0);
}