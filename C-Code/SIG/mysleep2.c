#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>


void func(int signum)
{

	printf("%dth signum -------\n",signum);
}


unsigned int mysleep(unsigned int seconds)
{
	struct sigaction act,oldact;

	act.sa_handler = func;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);

	int ret = sigaction(SIGALRM,&act,&oldact);
	if(ret == -1)
	{
		perror("sigaction error");
		exit(1);
	}
	alarm(seconds);
	unsigned int ret_pause = pause();
	if(ret == -1 && ret == EINTR)
	{
		printf("pause success\n");
	}



	int rett = alarm(0);


	sigaction(SIGALRM,&oldact,NULL);

	return rett;

}

int main()
{
	while(1){
		printf("start!\n");
		mysleep(3);
		printf("end!\n");
	}
	return 0;
}





