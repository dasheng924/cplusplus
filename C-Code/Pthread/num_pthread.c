//实验自己的电脑一个进程里有几个线程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>



void *func(void* argc)
{
	while(1)
		sleep(1);
}


int main()
{
	pthread_t tid;
	int count = 0;
	while(1)
	{
		int ret = pthread_create(&tid,NULL,func,NULL);
		if(ret != 0)
		{
			fprintf(stderr,"pthread_create :%s\n",strerror(ret));
			break;
		}
		++count;
		printf("%d th pthread\n",count);
	}
	return 0;
}