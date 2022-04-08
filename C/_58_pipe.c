//匿名管道：在血缘关系的进程间进行通信

/*
需求描述:
   在父进程中创建一个子进程, 父子进程分别执行不同的操作:
     - 子进程: 执行一个shell命令 "ps aux", 将命令的结果传递给父进程
     - 父进程: 将子进程命令的结果输出到终端
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{   

#if 1

    //1.创建管道
    int pipefd[2];
    int ret_pipe = pipe(pipefd);
    if(ret_pipe == -1)
    {
        perror("pipe fail!");
        return -1;
    }

    //2.创建父子进程，子进程拷贝了父进程的文件描述符表

    pid_t pid = fork();
    if(pid == 0)//3.子进程关闭读端，重定向结果到管道的写端
    {
        close(pipefd[0]) ;//子进程关闭读端
        //printf("我是子进程，我的ID是%d\n",getpid());
        dup2(pipefd[1],STDOUT_FILENO) ;//重定向
        execlp("ps","ps","aux",NULL);//执行ps aux
    }
    else if(pid >0)//4.关闭写端，循环读出管道的内容
    {
        close(pipefd[1]);
        char buf[4096];
        while(1)
        {
            memset(buf,0,sizeof(buf));
            int ret_read = read(pipefd[0],buf,sizeof(buf));
            
            if(ret_read == 0) //写端关闭，读端读出的结果为0，代表读完了
            {
                break;
            }
            printf("-------->%d\n",ret_read);
            printf("%s\n",buf);
        }
        close(pipefd[1]); //关闭写端
        wait(NULL);//回收子进程，防止僵尸进程的产生
    }

#endif


    exit(0);
}

