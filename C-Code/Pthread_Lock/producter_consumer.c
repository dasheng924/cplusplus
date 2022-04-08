#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

struct msg{
	int num;
	struct msg*next;
};

struct msg*head = NULL;//头结点
struct msg*mp = NULL;//结点


//pthread_mutex_t mt;
//pthread_cond_t ct;

//pthread_mutex_init(mt,NULL);
//pthread_cond_init(&ct,NULL);

pthread_cond_t ct = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mt = PTHREAD_MUTEX_INITIALIZER;

void err_int(int ret,const char*str)
{
	if(ret != 0)
	{
		fprintf(stderr,"%s:%s\n",str,strerror(ret));
		exit(1);
	}
}


void * producter(void *arg)
{
	while(1){
	mp = malloc(sizeof(struct msg));
	mp->num = rand()%400 +1;
	printf("producted------%d\n",mp->num);

	pthread_mutex_lock(&mt);
	mp->next = head;
	head = mp;
	pthread_mutex_unlock(&mt);
	
	pthread_cond_signal(&ct);
	
	sleep(rand() % 5);
	
	}
	return NULL;
}

void * consumer(void *arg)
{
	while(1){
		pthread_mutex_lock(&mt);
	
		while(head == NULL){//生产者生产出了东西，消费者就不需要阻塞等待
			pthread_cond_wait(&ct,&mt);
		}
	
	
		mp = head;
		head = mp->next;
		pthread_mutex_unlock(&mt);
	
		printf("consumer-----%d\n",mp->num);
		free(mp);
		mp = NULL;
		
		sleep(rand() % 5);
	}
	
	return NULL;
}



int main()
{
	srand(time(NULL));
	
	pthread_t ptid,ctid;
	
	int pret = pthread_create(&ptid,NULL,producter,NULL);
	err_int(pret,"pthread_create");
	
	int cret = pthread_create(&ctid,NULL,consumer,NULL);
	err_int(cret,"pthread_create err");
	
	
	pthread_join(ptid,NULL);
	pthread_join(ctid,NULL);
	
	return 0;
}
