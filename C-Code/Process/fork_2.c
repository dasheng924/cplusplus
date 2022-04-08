/*************************************************************************
	> File Name: fork_2.c
	> Created Time: 一  3/ 2 19:05:51 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main()
{
	pid_t pid;
	int i  = 0;
	for(i = 0;i< 5;i++)
	{
		pid = fork();
		if(pid ==-1)
		{
			perror("fork fail");
			exit(1);
		}
		else if(pid == 0)
		{
			break;
		}
		printf("---------------------\n");
		printf("+++++++++++++++++++++\n");
		printf("---------------------\n");

	}

	if(i < 5)
	{
		sleep(i);
		printf("I am %d child,pid  = %u,ppid = %u\n",i+1,getpid(),getppid());
	}
	else
	{
		sleep(i);
		printf("I am  parent,pid = %u,ppid = %u\n",getpid(),getppid());
	}
	
	return 0;
}
