#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

//验证一下pthread_exit 和 pthread_detach

void *func(void * arg)
{
    for(int i = 0;i<10;++i)
    {
        printf("%ld-->%d\n",pthread_self(),i);
        usleep(rand()%5);
    }

    pthread_exit(NULL);
}
int main(void)
{
    pthread_t tid ;
    int ret =  pthread_create(&tid,NULL,func,NULL);
    if(ret ==-1)
    {
        perror("pthread_create fail!");
        exit(-1);
    }
    pthread_detach(tid); //线程分离 省去了pthread_join 

   // exit(0);//查看主线程退出，子线程还会继续运行吗？
    //这样的话？主线程会优先退出，导致地址空间被释放，子线程自然被释放掉了，子线程不会执行
    pthread_exit(NULL);
    /*
    只要调用该函数当前线程就马上退出了，
    并且不会影响到其他线程的正常运行，不管是在子线程或者主线程中都可以使用。

    */
}