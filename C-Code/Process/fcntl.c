/*************************************************************************
	> File Name: fcntl.c
	> Created Time: 日  3/ 1 17:26:35 2020
 ************************************************************************/
//fcntl()改变打开文件的属性（在文件打开的过程中修改文件的权限）
//比如打开文件的时候只能读  若要追加内容就得改变文件的属性
//
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main()
{
	int fd = open("test_fcntl.txt",O_RDWR | O_CREAT ,0665);
	if(fd ==-1)
	{
		perror("open fail");
		exit(1);
	}

	//往test_fcntl文件中写入内容
	char * buf = "hello,mac!";
	if(write(fd,buf,strlen(buf)) == -1)
	{
		perror("write fail");
		exit(1);
	}

	//使用F_GETFL命令得到文件状态标志
	int flag = fcntl(fd,F_GETFL);
	if(flag == -1)
	{
		perror("fcntl() FGETFL fail");
		exit(1);
	}

	//将文件的状态标志添加”追加写“
	
	flag |= O_APPEND;

	if(fcntl(fd,F_SETFL,flag) == -1)
	{
		perror("fcntl() F_SETFL fail");
		exit(1);
	}

	if(write(fd,buf,strlen(buf)) == -1)
	{
		perror("write again fail");
		exit(1);
	}


	close(fd);



	return 0;
}
