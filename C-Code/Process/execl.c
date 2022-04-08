/*************************************************************************
	> File Name: execl.c
	> Created Time: 二  3/ 3 17:47:37 2020
 ************************************************************************/
//exexl 加载一个进程，通过路径+程序名
//int execl(const char*path,const char*arg,...)  参数1 使用绝对路径来搜索
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
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
		execl("/bin/ls","ls","-l","-a",NULL);//路径+程序名+参数
	}


	return 0;
}
