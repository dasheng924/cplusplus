/*************************************************************************
	> File Name: sid_fork_kill.c
	> Created Time: 二  3/10 17:14:09 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define N 5

int main()
{
	pid_t pid,pid_3;
	int i = 0;
	
	for(i = 0;i < N;i++)
	{
		pid = fork();
		if(pid == -1)
		{
			perror("fork error");
			exit(1);
		}
		else if (pid == 0)
		{
			break;
		}

		if (i == 2)
		{
			pid_3 = pid;
		}
		

	}

	if(i < N)
	{
		while(1)
			printf("I am %dth child,pid = %u\n",i+1,getpid());
			sleep(2);
	}
	else
	{
		sleep(1);
		int ret = kill(pid_3,SIGKILL);
		if(ret == -1)
		{
			perror("kill error");
			exit(1);
		}

		while(1);

	}

	return 0;
}
