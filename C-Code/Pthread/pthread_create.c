/*************************************************************************
	> File Name: pthread_create.c
	> Created Time: 日  3/15 17:50:48 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void * pthread_func(void *arg)
{
	pthread_t id = pthread_self();
	printf("pthread id = %lu,pid = %u\n",id,getpid());
	return NULL;
}

int main()
{

	pthread_t pid;
	int ret = 0;
	ret = pthread_create(&pid,NULL,pthread_func,NULL);
	if(ret != 0)
	{
		printf("pthread_create error!\n");
		exit(1);
	}
	sleep(1);
	return 0;
}
