#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void * pthread_func(void *argc)
{
	printf("tid  = %lu\n",pthread_self());
	return NULL;//这里的return 是回到了调用的那个位置，切不可在线程里面使用exit函数退出
}

int main()
{
	pthread_t tid;
	int ret = pthread_create(&tid,NULL,pthread_func,NULL);
	if(ret != 0)
	{
		printf("pthread_create error :%s\n",strerror(ret));
		exit(1);
	}
	
	pthread_exit(NULL);//若不加这个，使用return 0 的话，进程会大概率的先退出，导致线程的函数无法输出
	//也就是上面的pthread_func()函数无法输出
	
	//return 0;
	
}