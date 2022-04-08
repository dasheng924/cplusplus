//死锁状态1：对一个已拥有的互斥量加锁两次

#include <stdio.h>
#include <pthread.h>


int a= 10;


int main()
{
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex,NULL);

	pthread_mutex_lock(&mutex);
	a = 200;
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
	
	printf("a = %d-----\n",a);//死锁，a值无法输出

	pthread_mutex_destroy(&mutex);

	return 0;
}