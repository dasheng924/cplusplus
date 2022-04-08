#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_COUNT 50
int num;

pthread_rwlock_t rwlock;


void *func_r(void *arg)
{
    for(int i = 0;i<MAX_COUNT;++i)
    {
        pthread_rwlock_rdlock(&rwlock);
        printf("%s-->%lu-->%d\n",__FUNCTION__,pthread_self(),num);
        pthread_rwlock_unlock(&rwlock);
        usleep(rand()%5);
    }
    pthread_exit(NULL);
}

void * func_w(void *arg)
{
    for(int i = 0;i<MAX_COUNT;++i)
    {
        pthread_rwlock_wrlock(&rwlock);
        int cur = num;
        cur++;
        num = cur;
        printf("%s-->%lu-->%d\n",__FUNCTION__,pthread_self(),num);
        pthread_rwlock_unlock(&rwlock);
        usleep(rand()%5);
    }
    pthread_exit(NULL);

}
int main(void)
{
    pthread_rwlock_init(&rwlock,NULL);

    pthread_t tid_r[5],tid_w[3];
    for(int i = 0;i<5;++i)
    {
        pthread_create(&tid_r[i],NULL,func_r,NULL);
    }
    for(int i = 0;i<3;++i)
    {
        pthread_create(&tid_w[i],NULL,func_w,NULL);
    }

    for(int i = 0;i<5;++i)
        pthread_join(tid_r[i],NULL);
    for(int i = 0;i<3;++i)
        pthread_join(tid_w[i],NULL);

    pthread_rwlock_destroy(&rwlock);

    pthread_exit(NULL);
}
