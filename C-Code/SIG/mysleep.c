/*************************************************************************
	> File Name: mysleep.c
	> Created Time: 五  3/13 13:23:16 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>



void catch_signal(int signum)
{
	printf("捕捉函数%d\n",signum);
}


unsigned int mysleep(unsigned seconds)
{

	struct sigaction act,oldact;
	act.sa_handler = catch_signal;//捕捉函数绑定
	sigemptyset(&act.sa_mask);//清空信号集
	act.sa_flags = 0;//默认属性

	sigaction(SIGALRM,&act,&oldact);//注册捕捉函数

	alarm(seconds);//开始定时

	int ret = pause();//将进程主动挂起，等待SIGALRM信号激活
	if(ret == -1 && ret == EINTR)
	{
		perror("pause success");
	}

	unsigned int rett = alarm(0);//取消定时
	sigaction(SIGALRM,&oldact,NULL);//恢复SIGALRM默认处理动作


	return rett;


}




int main()
{
	do{
	printf("start!\n");
	mysleep(3);
	printf("end!\n");
	}while('q' !=  getchar());

	return 0;
}
