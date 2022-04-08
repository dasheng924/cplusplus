#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void  func(int signum)
{
	printf("%d signal,hello---------\n",signum);
	sleep(7);
}

int main()
{
	struct	sigaction act;

	act.sa_handler = func;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_flags = 0;

	sigaction(SIGINT,&act,NULL);

	while(1);

	return 0;
}