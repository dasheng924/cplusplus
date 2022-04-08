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

	
	//打开这个fifo
	int fd = open("fifo",O_RDONLY);
	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}

	//本进程单独的往fifo里面写入内容
	char buf[1024] ={0};
	int ret_read = read(fd,buf,sizeof(buf));
	if(ret_read == -1)
	{
		perror("write error");
		exit(1);
	}
	printf("读到的字节数为：%d\n",ret_read);
	write(STDOUT_FILENO,buf,ret_read);

	close(fd);
	

	


	return 0;
}
