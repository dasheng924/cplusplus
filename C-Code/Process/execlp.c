/*************************************************************************
	> File Name: execlp.c
	> Created Time: 二  3/ 3 17:57:20 2020
 ************************************************************************/
//execlp  参数1 使用程序名在PATH搜索    参数2为程序名（argv[0]） 参数3 对应参数
//int execlp(const char*file,const char*arg,...)
// 
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	pid_t pid = fork();
	if(pid ==-1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid >0)
	{
		sleep(1);
		printf("parent\n");
	}
	else
	{
		execlp("ls","ls","-a","-l",NULL);
	}
	return 0;
}
