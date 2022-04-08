#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>



void* pthread_func1(void *argc)
{
	return (void*)111;
}

void* pthread_func2(void *argc)
{
	return (void*)222;
}

void* pthread_func3(void *argc)
{
	while(1)
	{
		pthread_testcancel();
	}
}

int main()
{
	pthread_t tid;
	void * tret;
	
	int ret1 = pthread_create(&tid,NULL,pthread_func1,NULL);
	if(ret1 != 0)
	{
		fprintf(stderr,"pthread_create error:%s\n",strerror(ret1));
		exit(1);
	}
	pthread_join(tid,&tret);
	printf("1th pthread is %d\n",(int)tret);
	
	int ret2 = pthread_create(&tid,NULL,pthread_func2,NULL);
	if(ret2 != 0)
	{
		fprintf(stderr,"pthread_create error:%s\n",strerror(ret2));
		exit(1);
	}
	pthread_join(tid,&tret);
	printf("2th pthread is %d\n",(int)tret);
	
	
	int ret3 = pthread_create(&tid,NULL,pthread_func3,NULL);
	if(ret3 != 0)
	{
		fprintf(stderr,"pthread_create error:%s\n",strerror(ret3));
		exit(1);
	}
	sleep(2);
	pthread_cancel(tid);
	pthread_join(tid,&tret);
	printf("3th pthread is %d\n",(int)tret);
	
	return 0;
}