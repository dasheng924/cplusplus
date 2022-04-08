#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define N 5

void int_err(int ret,const char *str)
{
	if(ret != 0){
	fprintf(stderr,"%s:%s\n",str,strerror(ret));
	exit(1);
	}
}


void * func(void *arg)
{
	int i = (int)arg;
	printf("I am %dth thread,My id = %lu\n",i+1,pthread_self());

	return NULL;
}



int main(void)
{
	pthread_t tid[N];
	int ret;
	int i = 0;

	for(i = 0;i < N;i++)
	{
		ret = pthread_create(&tid[i],NULL,func,(void*)i);
		int_err(ret,"pthread_create error");
	}

	sleep(N);


	return 0;
}