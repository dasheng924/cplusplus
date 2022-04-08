/*************************************************************************
	> File Name: wait.c
	> Created Time: 三  3/ 4 02:35:07 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid,wpid;
	int i = 0,n = 3;
	int status;
	
	for(i = 0;i<3;i++)
	{
		pid = fork();
		if(pid == -1)
		{
			perror("fork error");
			exit(1);
		}
		else if(pid == 0)
		{
			break;
		}
		else if (pid >0)//父进程
		{
			wpid = waitpid(-1,&status,0);//参3为0 表示阻塞等待
			
			if(WIFEXITED(status))
			{
				printf("退出值为%d\n",WEXITSTATUS(status));
			}

			if(WIFSIGNALED(status))
			{
				printf("异常退出值%d\n",WTERMSIG(status));
			}
		}
	}

	if(i == 0)//第一个子进程
	{
		execlp("ps","ps","aux",NULL);
	}
	else if(i == 1)
	{
		execl("test_wait","test_wait",NULL);
	}
	else if(i == 2)
	{
		execl("test_wait1","test_wait1",NULL);
	}
	




	return 0;
}
