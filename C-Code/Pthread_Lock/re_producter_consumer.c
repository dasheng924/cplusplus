#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;
struct msg{
	int num;
	struct msg * next;
};

struct msg * head = NULL;
struct msg * mp = NULL;


void *producter(void *arg)
{
	while(1){
		mp = malloc(sizeof(struct msg));
		mp->num = rand() % 500+1;
		printf("producter-----%d\n",mp->num);
		pthread_mutex_lock(&mutex);
		mp->next = head;
		head = mp;
		pthread_mutex_unlock(&mutex);

		pthread_cond_signal(&cond);
		sleep(rand()%5);
	}
	return NULL;
}

void *consumer(void *arg)
{
	while(1){
		pthread_mutex_lock(&mutex);
		while(head == NULL)
		{
			pthread_cond_wait(&cond,&mutex);
		}
		mp = head;
		head = mp->next;
		pthread_mutex_unlock(&mutex);

		printf("consumer-----%d\n",mp->num);
		free(mp);
		mp = NULL;
		sleep(rand()%5);
	}
	return NULL;
}


int main()
{
	srand(time(NULL));
	pthread_t ptid,ctid;

	int ret_p = pthread_create(&ptid,NULL,producter,NULL);
	if(ret_p != 0)
	{
		fprintf(stderr,"pthread_create err:%s\n",strerror(ret_p));
		exit(1);
	}
	int  ret_c = pthread_create(&ctid,NULL,consumer,NULL);
	if(ret_c != 0)
	{
		fprintf(stderr,"pthread_create err:%s\n",strerror(ret_c));
		exit(1);
	}

	pthread_join(ptid,NULL);
	pthread_join(ctid,NULL);




	return 0;

}