/*************************************************************************
	> File Name: mmap_fork.c
	> Created Time: 四  3/ 5 17:25:36 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>


int main()
{
	//先打开一个文件获取文件的描述符
	int fd = open("mmap_fork.txt",O_RDWR | O_CREAT ,0664);
	if(fd == -1)
	{
		perror("open fail");
		exit(1);
	}
	
	unlink("mmap_fork.txt");//使进程结束时自动删除这个文件

	//设定获取文件的长度
	int ret = ftruncate(fd,10);
	if(ret == -1 )
	{
		perror("ftruncate fail");
		exit(1);
	}

	//使用mmap建立映射区
	char * p = mmap(NULL,10,PROT_WRITE | PROT_READ,MAP_SHARED,fd,0);
	if(p == MAP_FAILED)
	{
		perror("mmap fail");
		exit(1);
	}

	close(fd);

	//经过上面的步骤，硬盘映射到内存上的缓冲区设定完成
	//使用fork 产生父子进程操作这块缓存区
	//
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork fail");
		exit(1);
	}
	else if(pid == 0)//让子进程往共享内存处写入数据
	{
		char *buf = "day day up up up up up!";
		//通过指针p操纵这块内存
		strncpy(p,buf,10);
	}
	else//让父进程从共享内存处读出数据，然后把读到的数据打印到屏幕上
	{
		sleep(1);
		printf("父进程读出的数据:%s\n",p);
	}

	int ret_munmap = munmap(p,10);
	if(ret_munmap == -1)
	{
		perror("munmap fail");
		exit(1);
	}


	return 0;
}

