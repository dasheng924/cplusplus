#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if(pid == 0)
    {
        #if 0
        //参数1 要跟的是绝对路径
        execl("/bin/ps","Screen","a",NULL);
        printf("如果没有执行成功，才会打印出这句话！\n"); 
        #else
        //参数1 在环境变量里面能搜索到，就直接写名字就可以了  
        execlp("ps","Screen","au",NULL);
        #endif

    }
    else if(pid > 0 )
    {
        printf("我是父进程，我的ID是%d\n", getpid());
    }
    else{

        perror("fork() 调用失败！");
    }

    return 0;
}