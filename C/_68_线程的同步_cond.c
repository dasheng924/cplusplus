#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
/*
一个线程等待"条件变量的条件成立"而挂起；
另一个线程使"条件成立"（给出条件成立信号）。
为了防止竞争，条件变量的使用总是和一个互斥锁结合在一起。  
https://blog.csdn.net/hairetz/article/details/4535920
*/





#define THREAD_NUM 4

pthread_cond_t cond;
pthread_mutex_t mutex;

int count = 0;                                                                                
//4个线程 对于全局变量count ，线程1，2 每次+1 ，线程3 每次-1 。线程4 当count >=100时，重置为0

void *func_add(void *arg)
{
    pthread_mutex_lock(&mutex);
    count++;
    pthread_mutex_unlock(&mutex);
    printf("count = %d\t加了一次\n",count);
    if(count >=100)
    {
        pthread_cond_signal(&cond);
    }
    

    pthread_exit(NULL);
}

void *func_minus(void *arg)
{
    pthread_mutex_lock(&mutex);
    count--;
    pthread_mutex_unlock(&mutex);
    printf("count = %d\t减了一次\n",count);
    
    pthread_exit(NULL);
}


void *func_reset(void *arg)
{
    pthread_mutex_lock(&mutex);
    while(1)
    { 
        while(count < 100)
        {
            pthread_cond_wait(&cond,&mutex) ;
        }
        printf("count --->100\n");
        count = 0 ;
        pthread_mutex_unlock(&mutex);
    }


    pthread_exit(NULL);
}


void printErr(const int num,const char * str)
{
    if(str != NULL && num == -1)
    {
        perror(str);
    }
}



int main(void)
{

    pthread_cond_init(&cond,NULL);
    pthread_mutex_init(&mutex,NULL);


   pthread_t tid[THREAD_NUM] ;
   int ret ;
 

    ret = pthread_create(&tid[0],NULL,func_add,NULL);
    printErr(ret,"pthread_create error!");
    ret = pthread_create(&tid[1],NULL,func_add,NULL);
    printErr(ret,"pthread_create error!");
    ret = pthread_create(&tid[2],NULL,func_minus,NULL);
    printErr(ret,"pthread_create error!");
    ret = pthread_create(&tid[3],NULL,func_add,NULL);
    printErr(ret,"pthread_create error!");
 

    for(int i = 0;i<THREAD_NUM;++i)
        pthread_join(tid[i],NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    pthread_exit(NULL);

}


