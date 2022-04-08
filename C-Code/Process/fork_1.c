/*************************************************************************
	> File Name: fork_1.c
	> Created Time: 一  3/ 2 18:29:21 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	pid_t pid;
	printf("xxxxxxxxxxxxx\n");
	
	pid = fork();
	if(pid == -1)
	{
		perror("fork fail");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("I am child,pid = %u,ppid = %u\n",getpid(),getppid());
	}
	else
	{
		sleep(1);
		printf("I am parent,pid = %u,ppid = %u\n",getpid(),getppid());
		//sleep(1);//让子进程先退出
	}

	printf("YYYYYYYYYYYYYYY\n");




	return 0;
}
