/*************************************************************************
	> File Name: unlink.c
	> Created Time: 五  2/28 16:43:40 2020
 ************************************************************************/
//创建一个临时文件，当你不用了之后，自动删除这个文件
//unlink 会针对打开的文件不删除，知道这个文件关闭时才去删除这个文件，类似看电影的缓存文件

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	//先创建一个不存在的文件
	int fd = open("TempFile",O_RDWR | O_CREAT,0664);
	if(fd == -1)
	{
		perror("open file fail");
		exit(1);
	}
	//使用unlink删除掉这个已打开的文件
	int ret_link = unlink("TempFile");
	if(ret_link == -1)
	{
		perror("unlink fail");
		exit(1);
	}
	
	//模拟电影缓存，往这个文件里面写入内容
	int ret_write = write(fd,"hello,world\n",12);
	if(ret_write == -1)
	{
		perror("write fail");
		exit(1);
	}
	
	//重置文件指针
	lseek(fd,0,SEEK_SET);




	//证明这个文件还没有被删除，读出文件里面的东西
	char buf[32] = {0};
	int len = read(fd,buf,12);
	
	//把这个文件读出来，写到屏幕上去
	int ret_rewrite = write(1,buf,len);
	if(ret_rewrite == -1)
	{
		perror("rewrite fail");
		exit(1);
	}

	close(fd);

	return 0;
}

