#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

/*
一个线程等待"条件变量的条件成立"而挂起；
另一个线程使"条件成立"（给出条件成立信号）。
为了防止竞争，条件变量的使用总是和一个互斥锁结合在一起。  
https://blog.csdn.net/hairetz/article/details/4535920
*/

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
        pthread_mutex_lock(&mutex);
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->num = rand()%100 ;
        newnode->next = head ;
        head = newnode ;
        printf("生产者:%ld,number = %d\n",pthread_self(),newnode->num);
        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond) ;//有生产就去唤醒
        sleep(rand()%5);
    }

    return NULL ;
}


void *consumer(void *arg)
{

    while (1)
    {
        //当消费者拿到这把锁之后，生产者是否可以拿到锁？
        //pthread_mutex_lock pthread_cond_wait 是一个原子操作，
        //当有消费者成功阻塞在pthread_cond_wait，锁会打开
        pthread_mutex_lock(&mutex); 
        //这把锁是为了防止多个消费者线程阻塞在pthread_cond_wait
        while(head == NULL)//signal和wait之间是有时间差的，可能在间隙之间又会没有商品
        {
            //目前只有一个消费者线程阻塞在pthread_cond_wait
            pthread_cond_wait(&cond,&mutex) ; //阻塞消费者线程
            //唤醒之后会加锁成功才往下走
        }
        Node *p = head ;
        printf("消费者:%ld,number = %d\n",pthread_self(),p->num);
        head = head->next ;
        free(p);
        pthread_mutex_unlock(&mutex);

        sleep(rand()%5);
    }
    return NULL ;
}


int main()
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

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




    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);



}