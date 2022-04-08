#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

pthread_rwlock_t rwt;
int global  = 1;

void err_int(const int ret,const char *str)
{
	if(ret != 0)
	{
		fprintf(stderr,"%s:%s\n",str,strerror(ret));
		exit(1);
	}
}

void *func_r(void *arg)
{
	int val = (int)arg;
	while (1) {	
		pthread_rwlock_rdlock(&rwt);
		printf("%d thread_r ,global = %d\n",val+1,global);
		pthread_rwlock_unlock(&rwt);
		sleep(2);
	}
	
	return NULL;
	
}

void* func_w(void * arg)
{
	int vall = (int)arg;
	while (1) {
		pthread_rwlock_wrlock(&rwt);
		printf("%dth thread_w ,global = %d\n",vall+4,(++global));
		pthread_rwlock_unlock(&rwt);
		sleep(2);
	}
	return NULL;
}



int main()
{
	pthread_t tid_r[3];
	pthread_t tid_w[5];
	int i;
	//初始化读写锁
	pthread_rwlock_init(&rwt,NULL);
	
	for(i = 0;i<3;i++)
	{
		int ret = pthread_create(&tid_r[i],NULL,func_r,(void*)i);
		err_int(ret,"pthread_create err");
	}
	for(i = 0;i<5;i++)
	{
		int ret1 = pthread_create(&tid_w[i],NULL,func_w,(void*)i);
		err_int(ret1,"pthread_create err");
	}
	
	for(i = 0;i<3;i++)
	{
		pthread_join(tid_r[i],NULL);
	}
	for(i = 0;i<5;i++)
	{
		pthread_join(tid_w[i],NULL);
	}
	
	pthread_rwlock_destroy(&rwt);
	
	
	return 0;
}
