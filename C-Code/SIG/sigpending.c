#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void print_sig(const sigset_t * set)
{
	int i;
	for(i = 1;i < 32;i++)
	{
		if(sigismember(set,i)){
			putchar('1');
		}
		else{
			putchar('0');
		}
	}
	printf("\n");
}


int main()
{
	sigset_t myset,pendset;

	sigemptyset(&myset);
	sigaddset(&myset,SIGINT);
	sigaddset(&myset,SIGTSTP);
	sigaddset(&myset,SIGQUIT);

	sigprocmask(SIG_BLOCK,&myset,NULL);

	while(1){
		sigpending(&pendset);
		print_sig(&pendset);
		sleep(2);
	}
	return 0;
}