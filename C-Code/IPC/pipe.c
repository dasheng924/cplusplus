/*************************************************************************
	> File Name: pipe.c
	> Created Time: 三  3/ 4 15:46:03 2020
 ************************************************************************/
//测试管道
//子进程读   父进程写
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	//先创建一个管道
	int fd[2] = {0};
	pid_t pid;
	int ret = pipe(fd);
	if(ret == -1)
	{
		perror("pipe error");
		exit(1);
	}
	//产生了两个文件描述符  fd[0] ---> r   fd[1]  ---> w
	
	//使用fork产生父子进程
	pid = fork();
	if(pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		//子进程读，关闭写端
		close(fd[1]);
		char buf[1024] = {0};
		int len = read(fd[0],buf,sizeof(buf));

		//把读到的内容放到屏幕
		write(STDOUT_FILENO,buf,len);

		sleep(fd[0]);
	}
	else
	{
		//关闭读端
		close(fd[0]);

		write(fd[1],"hello,world\n",strlen("hello,world\n")+1);
		close(fd[0]);

	}


	return 0;
}
