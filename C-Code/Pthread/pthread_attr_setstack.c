#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define SIZE 0x10000

void *func(void*argc)
{
	while(1)
		sleep(1);
}

int main()
{
	//线程属性
	pthread_attr_t attr;
	pthread_t tid;
	void *stackaddr;
	size_t stacksize;
	int count = 0;
	int detachstate;
	pthread_attr_init(&attr);//初始化线程属性
	pthread_attr_getstack(&attr,&stackaddr,&stacksize);//获取线程的栈地址
	pthread_attr_getdetachstate(&attr,&detachstate);//获取线程的分离状态
	
	
	if(detachstate == PTHREAD_CREATE_DETACHED){
		printf("thread detached\n");
	}
	else if (detachstate == PTHREAD_CREATE_JOINABLE) {
		printf("thread join\n");
	}
	else {
		printf("thread unknow\n");
	}
	
	
	//设置线程分离
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	
	while(1){
		stackaddr = malloc(sizeof(SIZE));//分配线程栈空间
		if(stackaddr == NULL){
			perror("malloc error");
			exit(1);
		}
		
		stacksize = SIZE;//保存线程栈大小
		
		pthread_attr_setstack(&attr,stackaddr,stacksize);//在堆上开辟内存设置线程栈
		int err = pthread_create(&tid,&attr,func,NULL);//创建线程
		if(err != 0)
		{
			fprintf(stderr,"pthread_create error:%s\n",strerror(err));
			exit(1);
		}
		++count;
		printf("thread %d\n",count);
	}
	
	pthread_attr_destroy(&attr);
	
	return	0;
	
	
	
}