/*************************************************************************
	> File Name: test_fifo.c
	> Created Time: 三  3/ 4 16:15:56 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main(void)
{

	//创建一个有名管道
	int ret = mkfifo("fifo",0777);
	if(-1 == ret)
	{
		perror("mkfifo error");
		exit(1);
	}
	
	//打开这个fifo
	int fd = open("fifo",O_WRONLY);
	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}

	//本进程单独的往fifo里面写入内容
	
	int ret_write = write(fd,"hello",strlen("hello"));
	if(ret_write == -1)
	{
		perror("write error");
		exit(1);
	}
	

	close(fd);	


	return 0;
}
