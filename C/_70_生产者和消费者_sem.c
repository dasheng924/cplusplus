#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>


sem_t sem_c;
sem_t sem_p;



typedef struct Node
{
    int num;
    struct Node *next;
}Node;

Node * head = NULL ; //头节点

void *producer(void *arg)
{

    while(1)
    {
        sem_wait(&sem_p); //检测生产者现有资源
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->num = rand()%100 ;
        newnode->next = head ;
        head = newnode ;
        printf("生产者:%ld,number = %d\n",pthread_self(),newnode->num);
        sem_post(&sem_c);
        sleep(rand()%5);
    }

    return NULL ;
}


void *consumer(void *arg)
{

    while (1)
    {
        sem_wait(&sem_c);

        Node *p = head ;
        printf("消费者:%ld,number = %d\n",pthread_self(),p->num);
        head = head->next ;
        free(p);
        sem_post(&sem_p);

        sleep(rand()%5);
    }
    return NULL ;
}


int main()
{
    // //生产者
    // sem_init(&sem_p,0,1); //生产者有一个资源
    // sem_init(&sem_c,0,0);

    sem_open("sem_p", O_CREAT|O_EXCL, S_IRWXU, 0) ;
    sem_open("sem_c", O_CREAT|O_EXCL, S_IRWXU, 0);


    pthread_t tid1[5],tid2[5];
    for(int i = 0;i<5;++i)
    {
        pthread_create(&tid1[i],NULL,producer,NULL);
    }
      for(int i = 0;i<5;++i)
    {
        pthread_create(&tid2[i],NULL,consumer,NULL);
    }

      for(int i = 0;i<5;++i)
    {
        pthread_join(tid1[i],NULL);
        pthread_join(tid2[i],NULL);
    }



    // sem_destroy(&sem_p);
    // sem_destroy(&sem_c);

    sem_unlink("sem_p");
    sem_unlink("sem_c");


}