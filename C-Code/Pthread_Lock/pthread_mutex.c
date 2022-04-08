#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mt;

void* func(void * arg)
{
	int i = 5;
	while(i--){
	pthread_mutex_lock(&mt);
	srand(time(NULL));
	printf("hello ");
	sleep(rand()%3);
	printf("world\n");
	pthread_mutex_unlock(&mt);
	sleep(rand()%3);
	}
	
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	//pthread_mutex_t mt;
	pthread_mutex_init(&mt,NULL);//初始化互斥量
	
	int ret = pthread_create(&tid,NULL,func,NULL);//创建子线程
	if(ret != 0)
	{
		fprintf(stderr,"pthread_create error:%s\n",strerror(ret));
		exit(1);
	}
	//pthread_detach(tid);//线程分离
	int i = 3;
	while(i--){
	pthread_mutex_lock(&mt);
	
	printf("HELLO ");
	srand(time(NULL));
	sleep(rand()%3);
	printf("WORLD\n");
	pthread_mutex_unlock(&mt);
	sleep(rand()%3);
}
	//pthread_cancel(tid);
	pthread_join(tid,NULL);	
	
	pthread_mutex_destroy(&mt);
	return 0;
}