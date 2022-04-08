//两个线程互相在屏幕打印出hello world 和 HELLO WORLD 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>


pthread_mutex_t mutex;



void err(int ret,const char * str)
{
	if(ret != 0)
	{
		fprintf(stderr,"%s:%s\n",str,strerror(ret));
		exit(1);
	}
}

void * func(void * arg)
{
	srand(time(NULL));
	int j = 8;
	while(j--)
	{
		pthread_mutex_lock(&mutex);
		printf("HELLO");
		sleep(rand()%5);
		printf(" WORLD\n");
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}



int main()
{
	pthread_t tid;
	
	pthread_mutex_init(&mutex,NULL);

	int ret = pthread_create(&tid,NULL,func,NULL);
	err(ret,"pthread create err");
	
	int i = 5;
	srand(time(NULL));
	while(i--)
	{
		pthread_mutex_lock(&mutex);
		printf("hello");
		sleep(rand()%5);
		printf(" world\n");
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);

	}
	
	pthread_mutex_destroy(&mutex);
	
	pthread_cancel(tid);//若想主线程打印完5次退出子线程，那就需要杀死子线程
	pthread_join(tid,NULL);



	return 0;
}