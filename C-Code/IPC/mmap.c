/*************************************************************************
	> File Name: mmap.c
	> Created Time: 三  3/ 4 20:35:52 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>


int main()
{

	//mmap借助文件描述符把磁盘文件映射到内存的缓冲区上，故先open文件，获取文件描述符
	char * p = NULL;//用来接受mmap函数的返回值


	int fd = open("test_mmap",O_RDWR | O_CREAT,0644);
	if(fd == -1)
	{
		perror("open fail");
		exit(1);
	}

	//获取文件长度,使用ftruncate()
	int ret = ftruncate(fd,8);//设定该文件的大小为4k
	if(ret == -1)
	{
		perror("ftruncate fail");
		exit(1);
	}

	//使用mmap函数来映射  共6个参数
	p = mmap(NULL,8,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	if(p == MAP_FAILED)
	{
		perror("mmap fail");
		exit(1);
	}

	//往该缓冲区写入数据
	char * str = "day day up";
	strcpy(p,str);
	int ret_munmap = munmap(p,8);//释放映射
	if(ret_munmap == -1)
	{
		perror("munmap fail");
		exit(1);
	}

	close(fd);

	return 0;
}
