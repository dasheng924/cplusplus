#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_COUNT  50

pthread_mutex_t mutex;
int num ;

void *func1(void *arg)
{
    for(int i = 0;i<MAX_COUNT;++i)
    {
        pthread_mutex_lock(&mutex);
        int cur = num;
        cur++;
        num = cur;
        printf("%s-->%ld-->num = %d\n",__FUNCTION__,pthread_self(),num);
        pthread_mutex_unlock(&mutex);
        usleep(rand()%5);
    }
    pthread_exit(NULL);
}
void *func2(void *arg)
{
    for(int i = 0;i<MAX_COUNT;++i)
    {
        pthread_mutex_lock(&mutex);
        int cur = num;
        cur++;
        num = cur;
        printf("%s-->%ld-->num = %d\n",__FUNCTION__,pthread_self(),num);
        pthread_mutex_unlock(&mutex);
        usleep(rand()%5);
    }
    pthread_exit(NULL);
}

int main(void)
{

    pthread_t tid1,tid2; 
    pthread_mutex_init(&mutex,NULL);

    int ret1,ret2;
    ret1 = pthread_create(&tid1,NULL,func1,NULL);
    if(ret1 == -1)
    {
        perror("pthread_create tid1 error!");
        exit(-1);
    }
    ret2 = pthread_create(&tid2,NULL,func2,NULL);
      if(ret2 == -1)
    {
        perror("pthread_create tid2 error!");
        exit(-1);
    }

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    

    pthread_exit(NULL);
    pthread_mutex_destroy(&mutex);
}