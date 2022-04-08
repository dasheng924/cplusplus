/*************************************************************************
	> File Name: execl.c
	> Created Time: 二  3/ 3 17:47:37 2020
 ************************************************************************/
//exexle 加载一个进程，通过路径+程序名+environ
//int execle(const char*path,const char*arg,...,char *const envp[])  参数1 使用绝对路径来搜索
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main()
{
	char * env_init[] = {"AA=123","BB=456"};
	pid_t pid;
	pid = fork();
	if(-1 == pid)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid > 0)
	{
		sleep(1);
		printf("parent\n");
	}
	else
	{
		for(int i = 0;environ[i];i++)
			execle("/bin/ls","ls","-l","-a",NULL,env_init);//路径+程序名+参数
	}


	return 0;
}
