#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void * pthread_func(void * argc)
{
	int i = 3;
	while(i--)
	{
		printf("hello mac\n");
	}
	sleep(1);
	return (void*)1;
}

int main()
{
	pthread_t tid;
	int ret,ret_join;
	void * tret;
	ret = pthread_create(&tid,NULL,pthread_func,NULL);
	if(ret != 0)
	{
		fprintf(stderr,"pthread_create error:%s\n",strerror(ret));
		exit(1);
	}
	pthread_detach(tid);
	
	while(1)
	{
		ret_join = pthread_join(tid,&tret);//回收子线程，同时返回错误码
		if(ret_join != 0)
		{
			fprintf(stderr,"pthread_join error:%s\n",strerror(ret_join));
		}
		else {
			fprintf(stderr,"pthread_join ok:%d\n",(int)tret);
		}
		sleep(1);
	}
	
	
	pthread_exit(NULL);
}