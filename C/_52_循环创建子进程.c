#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{

    pid_t pid;
    
    for(int i = 0;i<3;++i)
    {
        pid = fork();
        if(pid == 0 )
        {
            //子进程直接退出,保证子进程全部退出循环，只有父进程参与到fork的循环中
            break;
            
        }
    }
    //当前进程的pid
    //sleep(1);
    printf("当前进程的pid = %d\n",getpid());
    //最小的pid 就是父进程





    return 0;
}