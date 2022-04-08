#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>



#define NUM 10
sem_t sem_p,sem_c;
int queue[NUM];


void * fun_p(void * arg)
{
	int i = 0;
	while(1)
	{
		sem_wait(&sem_p);
		queue[i] = rand()%1000+1;
		printf("----producter %d-----\n",queue[i]);
		sem_post(&sem_c);
		i = (i+1)%NUM;
		sleep(rand()%3);

	}
	return NULL;
}

void * fun_c(void * arg)
{
	int i = 0;
	while(1)
	{
		sem_wait(&sem_c);
		printf("------consumer  %d\n",queue[i]);
		queue[i] = 0;
		sem_post(&sem_p);

		i = (i+1)%NUM;
		sleep(rand()%3);

	}
	return NULL;
}



int main()
{
	sem_init(&sem_p,0,NUM);
	sem_init(&sem_c,0,0);

	
	srand(time(NULL));
	pthread_t ctid,ptid;


	int ret_p = pthread_create(&ptid,NULL,fun_p,NULL);
	if(ret_p != 0)
	{
		fprintf(stderr,"Pthread_create error:%s\n",strerror(ret_p));
		exit(1);
	}
	int ret_c = pthread_create(&ctid,NULL,fun_c,NULL);
	if(ret_c != 0)
	{
		fprintf(stderr,"Pthread_create error:%s\n",strerror(ret_c));
		exit(1);
	}

	pthread_join(ptid,NULL);
	pthread_join(ctid,NULL);
//	sem_destroy(&sem_p);
//	sem_destroy(&sem_c);
	return 0;




}