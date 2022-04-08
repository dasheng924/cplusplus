/*************************************************************************
	> File Name: sig_set.c
	> Created Time: 三  3/11 16:59:25 2020
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void print_set(sigset_t * set)
{
	if(set == NULL)
	{
		exit(1);
	}

	int i ;
	for(i = 1;i<32;i++)
	{
		if(sigismember(set,i))
		{
			putchar('1');
		}
		else
		{
			putchar('0');
		}
	}

	printf("\n");
}




int main()
{
	//定义自己的信号集合未决信号集的参数
	//
	sigset_t myset,pset;

	sigemptyset(&myset);//将自己的信号集内的信号置0

	sigaddset(&myset,SIGINT);
	sigaddset(&myset,SIGTSTP);

	if(sigprocmask(SIG_BLOCK,&myset,NULL))
	{
		perror("sigprocmask error");
		exit(1);
	}

	while(1)
	{
		sigpending(&pset);
		print_set(&pset);
		sleep(3);
	}







	return 0;
}
