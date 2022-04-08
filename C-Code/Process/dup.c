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
	//先打开一个文件，并获取到文件描述符
	int fd = open("a.txt",O_RDWR | O_CREAT,0665);
	if(fd ==-1)
	{
		perror("open fail");
		exit(1);
	}
	//打印一下文件描述符
	printf("a.out filedes  = %d\n",fd);

	//使用dup()复制文件描述符
	int ret = dup(fd);
	if(ret == -1)
	{
		perror("dup fail");
		exit(1);
	}

	printf("new filedes  = %d\n",ret);

	char *buf1 = "hello";
	char *buf2 = "world";

	write(fd,buf1,strlen(buf1));

	write(ret,buf2,strlen(buf2));

	close(fd);



	return 0;
}
