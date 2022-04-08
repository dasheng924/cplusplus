#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>


void func(int signum)
{
	int status;
	pid_t pid;
	while((pid = waitpid(0,&status,WNOHANG)) > 0)//使用if不能让子进程回收完全
	{
		if(WIFEXITED(status))
			printf("child %d exit %d\n",pid,WEXITSTATUS(status));
		else if(WIFSIGNALED(status))
		{
			printf("child %d cancel signal %d\n",pid,WTERMSIG(status));
		}
	}
}



int main()
{
	pid_t pid;
	int i ;

	for(i = 0;i < 5;i++)
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
	}
	if(pid == 0)
	{
		int n = 1;
		while(n--)
		{
			printf("child id %d\n",getpid());
			sleep(1);
		}
		return i+1;//返回子进程推出值
	}
	else if(pid > 0)
	{
		struct sigaction act;
		act.sa_handler = func;
		act.sa_flags = 0;
		sigemptyset(&act.sa_mask);
		sigaction(SIGCHLD,&act,NULL);

		while(1)
		{
			printf("Parent id %d\n",getppid());
			sleep(1);
		}

		}
		return 0;

	}







