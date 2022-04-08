#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *pthread_func(void * argc)
{
	pthread_exit((void*)111);
}


int main()
{
	pthread_attr_t attr;
	int ret1 = pthread_attr_init(&attr);
	if(ret1 != 0)
	{
		fprintf(stderr,"pthread_init error:%s\n",strerror(ret1));
		exit(1);
	}
	int ret2 = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	if(ret2 != 0)
	{
		fprintf(stderr,"pthread_setdetachstate error:%s\n",strerror(ret2));
		exit(1);
	}
	pthread_t tid;
	int ret3 = pthread_create(&tid,&attr,pthread_func,NULL);
	if(ret3 != 0)
	{
		fprintf(stderr,"pthread_create error:%s\n",strerror(ret3));
		exit(1);
	}
	
	int ret4 = pthread_join(tid,NULL);
	fprintf(stderr,"pthread_join :%d\n",ret4);
	
	return 0;
}