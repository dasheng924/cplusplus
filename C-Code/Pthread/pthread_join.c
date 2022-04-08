#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct{
	char a;
	int b;
	char str[];
}st;

void * pthread_func(void * argc)
{
	//在main函数里面完成了内存的分配
	//st * st_a;
	//st_a = (st*)malloc(sizeof(st));
	st * st_a = (st*)argc;
	
	st_a->a = 'x';
	st_a->b = 10;
	strcpy(st_a->str,"hello mac!");
	pthread_exit((void *)st_a);//st_a 是一个局部结构体指针，在这个不能返回&st_a;故直接返回的是结构体的值
	
}

int main()
{
	pthread_t tid;
	st * st_b;
	st_b = (st*)malloc(sizeof(st));
	if(st_b == NULL)
	{
		perror("malloc error");
		exit(1);
	}
	//int ret = pthread_create(&tid,NULL,pthread_func,NULL);
	int ret = pthread_create(&tid,NULL,pthread_func,(void *)st_b);
	if(ret != 0)
	{
		printf("pthread_create error:%s\n",strerror(ret));
		exit(1);
	}
	
	pthread_join(tid,(void **)&st_b);//这里为什么要取地址，原因是原型里面是用二级指针来接受这个值
	printf("%c  %d %s\n",st_b->a,st_b->b,st_b->str);
	free(st_b);//在线程的主控函数里面分配的内存，在这里释放；不太方便，利用pthread_create 参三
	pthread_exit(NULL);
}