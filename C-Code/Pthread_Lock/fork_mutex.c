//直接利用互斥量是无法对进程进行加解锁，需要设置互斥锁的属性来达到在进程间使用

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>


struct mt
{
	int num;
	pthread_mutex_t mutex;
	pthread_mutexattr_t mutexattr;
};

int main()
{
	struct mt *mm;


	int fd = open("fork_mutex.txt",O_RDWR | O_CREAT | O_TRUNC,0644);
	if(fd == -1)
	{
		perror("open fail");
		exit(1);
	}
	//设定文件的长度
	ftruncate(fd,sizeof(*mm));

	//printf("%lu\n",sizeof(*mm));

	mm = mmap(NULL,sizeof(*mm),PROT_WRITE | PROT_READ,MAP_SHARED,fd,0);
	if(MAP_FAILED == mm)
	{
		perror("mmap error");
		exit(1);
	}

	unlink("fork_mutex.txt");
	close(fd);

	memset(mm,0,sizeof(*mm));

	pthread_mutex_init(&mm->mutex,&mm->mutexattr);//初始化一把mutex的锁
	pthread_mutexattr_init(&mm->mutexattr);//初始化mutex属性对象
	pthread_mutexattr_setpshared(&mm->mutexattr,PTHREAD_PROCESS_SHARED);//把mutex属性改为在进程间共享


	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		for(int i = 0;i < 10;i++)
		{
			pthread_mutex_lock(&mm->mutex);
			(mm->num)++;
			printf("---child---num++   %d\n",mm->num);
			pthread_mutex_unlock(&mm->mutex);
			sleep(10);

		}

	}
	else if(pid > 0)
	{
		for(int i = 0;i < 10;i++)
		{
			sleep(1);
			pthread_mutex_lock(&mm->mutex);
			mm->num += 2;
			printf("---parent---num+=2   %d\n",mm->num);
			pthread_mutex_unlock(&mm->mutex);
		}
		wait(NULL);
	}



	pthread_mutexattr_destroy(&mm->mutexattr);//销毁mutex属性对象
	pthread_mutex_destroy(&mm->mutex);
	munmap(mm,sizeof(*mm));


	return 0;
}
