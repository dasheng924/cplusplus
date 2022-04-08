/*************************************************************************
	> File Name: sigaction.c
	> Created Time: 三  3/11 20:05:44 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void cache_sign(int signum)
{
	printf("  %d -----------\n",signum);
	sleep(7);
	printf("finish\n");
}


int main()
{
	struct sigaction act;
	int ret;

 
	act.sa_handler = cache_sign;//注册函数
	sigemptyset(&act.sa_mask);//sa_mask 信号集合全部置0
	sigaddset(&act.sa_mask,SIGTSTP);//把 CTRL + z 的信号加入到sa_mask信号集合
	act.sa_flags = 0;//执行默认属性，在捕捉函数执行期间，自动屏蔽本信号
	
	//调用sigaction捕捉信号
	//
	ret = sigaction(SIGINT,&act,NULL);//函数在执行期间，自动屏蔽本信号。CRTL + C
	if(ret == -1)
	{
		perror("sigaction error");
		exit(1);
	}

	while(1);



	return 0;
}
