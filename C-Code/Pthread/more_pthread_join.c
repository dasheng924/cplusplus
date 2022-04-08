#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int g_val = 100;
void * pthread_func(void * argc)
{
	int i = (int)argc;
	sleep(i);
	if(i == 1)
	{
		g_val = 200;
		printf("%d th pythread %lu\n",i+1,pthread_self());
		pthread_exit((void*)g_val);
		
	}
	else if (i == 3) 
	{
		g_val = 300;
		printf("%d th pythread %lu\n",i+1,pthread_self());
		pthread_exit((void*)g_val);
		
	}
	else {
		g_val = 500;
		printf("%d th pythread %lu\n",i+1,pthread_self());
		return (void*)g_val;
	}
	
	return NULL;
}


int main()
{
	pthread_t tid[5];//保存线程ID
	int i;//循环因子
	int *arr[5];//用来保存5个子进程的退出值
	for(i = 0;i<5;i++)
	{
		int ret = pthread_create(&tid[i],NULL,pthread_func,(void*)i);//把循环因子作为参数
		if(ret != 0)
		{
			printf("pthread_create error:%s\n",strerror(ret));
			exit(1);
		}
	}
	
	//循环回收5个子进程，同时或得它们的退出值
	
	for(i = 0;i<5;i++)
	{
		pthread_join(tid[i],(void **)&arr[i]);
		printf("%d th pthread exit num ：%d\n",i+1,arr[i]);
	}
	
	pthread_exit(NULL);
	
}