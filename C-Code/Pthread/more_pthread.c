/*************************************************************************
	> File Name: more_pthread.c
	> Created Time: 日  3/15 18:23:03 2020
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void * pthread_func(void *argc)
{
	
	int i = (int)argc;
	sleep(i);
	printf("%dth pthread id = %lu,pid = %u\n",i,pthread_self(),getpid());
	return NULL;
}

void main()
{
	pthread_t pid[10];
	int ret,i = 0;
	for(i = 0;i< 10;i++)
	{
		ret = pthread_create(&pid[i],NULL,pthread_func,(void*)i);
		if(ret != 0)
		{
			printf("pthread_create error:%s\n",strerror(ret));
			exit(1);
		}
	}
	
	pthread_exit(NULL);//将主控线程退出
}
