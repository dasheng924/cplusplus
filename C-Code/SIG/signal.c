/*************************************************************************
	> File Name: signal.c
	> Created Time: 三  3/11 19:34:39 2020
 ************************************************************************/
//signal 信号捕捉函数，捕捉到设置好的信号，发生相对应的事
//
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


typedef void (*signhandler_t)(int);//函数指针

void cache_sign(int signum)
{
	printf("  %d ------------\n",signum);
}


int main()
{
	signhandler_t sign;
	sign = signal(SIGINT,cache_sign);
	if(sign == SIG_ERR)
	{
		perror("signal error");
		exit(1);
	}


	while(1);
	return 0;
}
