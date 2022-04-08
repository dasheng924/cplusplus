#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

//1.方法1:通过pthread_exit() 和 pthread_join()的配合来传递参数
//2.方法2:通过pthread_create()的最后一个参数来传递参数

struct Test
{
    int num;
    int age;
};

/*
方法1: 全局的定义
struct Test t;
*/
void *func(void *arg)
{
    struct Test *p = (struct Test*)arg;
    p->age = 111;
    p->num  = 111;

    for(int i = 0;i<10;++i)
    {
        printf("子线程i=%d\n",i);
    }
    printf("我是子线程，我的ID是%ld\n",(long)pthread_self());
    pthread_exit(p);

    return NULL;
}

int main(void)
{

    //方法二：把这个地址传递给子线程
    struct Test t;
    //先创建子线程
    pthread_t pthread_id;
    int ret = pthread_create(&pthread_id,NULL,func,&t);
    if(ret == -1)
    {
        perror("pthread_create error!");;
        exit(-1);
    }   
    printf("我是主线程，我的ID = %ld\n",(long)pthread_self());
    
#if 0 
    void * pp ;
    //回收子线程
    pthread_join(pthread_id,&pp);
    struct Test *p = (struct Test*)pp;
    printf("子线程改完之后的num = %d,age = %d\n",p->num,p->age);
#else
    pthread_join(pthread_id,NULL);
    printf("子线程改完之后的num = %d,age = %d\n",t.num,t.age);
#endif

    pthread_exit(NULL); //主线程退出




    exit(0);
}