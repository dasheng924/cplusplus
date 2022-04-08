/*************************************************************************
	> File Name: dup.c
	> Created Time: 日  3/ 1 15:44:44 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	//使用truncate()把已经存在的文件a.txt进行清空
	int ret_trun = truncate("a.txt",0);
	if(ret_trun == -1)
	{
		perror("truncate fail");
		exit(1);
	
	}
	printf("已清空a.txt的内容\n");
#ifdef _BUG_
	//先获取到a.txt的文件描述符
	int fd_a = open("a.txt",O_RDWR);
	if(fd_a == -1)
	{
		perror("fd_a is not ok");
		exit(1);
	}

	printf("a.txt-->old fd  = %d\n",fd_a);
	

	//先打开一个文件，并获取到文件描述符
	int fd = open("b.txt",O_RDWR | O_CREAT,0665);
	if(fd ==-1)
	{
		perror("open fail");
		exit(1);
	}
	//打印一下文件描述符
	printf("b.txt-->fd = %d\n",fd);

	//使用dup2()复制文件描述符
	int ret = dup2(fd_a,fd);
	if(ret == -1)
	{
		perror("dup2 fail");
		exit(1);
	}

	printf("new filedes  = %d\n",ret);

	char *buf1 = "hello";
	char *buf2 = "world";

	write(fd_a,buf1,strlen(buf1));

	write(fd,buf2,strlen(buf2));

	close(fd);
	close(fd_a);
#endif 




	return 0;
}
