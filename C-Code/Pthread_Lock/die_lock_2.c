#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int a = 10,b = 100; 

pthread_mutex_t mt1,mt2;

void err_int(const int ret,char *str)
{
	if(ret != 0)
	{
		fprintf(stderr,"%s:%s\n",str,strerror(ret));
		exit(1);
	}
	
}



void * func(void * arg)
{
	pthread_mutex_lock(&mt1);
	a = 11;
	sleep(2);
	pthread_mutex_lock(&mt2);//换成trylock
	b = 111;
	

	printf("a = %d, b = %d\n",a,b);
	pthread_mutex_unlock(&mt2);
	pthread_mutex_unlock(&mt1);
	
	printf("1 th thread finish\n");

	pthread_exit(NULL);
}

void * func2(void * arg)
{
	pthread_mutex_lock(&mt2);
	b = 222;
	sleep(3);

	pthread_mutex_lock(&mt1);//trylock
	a = 22;
	printf("a = %d, b = %d\n",a,b);
	pthread_mutex_unlock(&mt2);
	pthread_mutex_unlock(&mt1);

	printf("2 th thread finish\n");

	pthread_exit(NULL);
}


int main()
{
	pthread_t tid,tid2;
	//初始化锁
	pthread_mutex_init(&mt1,NULL);
	pthread_mutex_init(&mt2,NULL);
	
	
	int ret = pthread_create(&tid,NULL,func,NULL);
	err_int(ret,"pthread_create err");
	
	int ret2 = pthread_create(&tid2,NULL,func2,NULL);
	err_int(ret2,"pthread_create2 err");
	
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	
	int ret_des1 = pthread_mutex_destroy(&mt1);
	int ret_des2 = pthread_mutex_destroy(&mt2);
	if(ret_des1 == 0 && ret_des2 == 0)
	{
		printf("destroy finish!\n");
	}



	return 0;
}