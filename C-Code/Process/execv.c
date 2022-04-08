/*************************************************************************
	> File Name: execv.c
	> Created Time: 日  3/ 8 22:29:49 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char * argv[] = {"ls","-a","-l",NULL};

	int ret = execv("/bin/ls",argv);
	if(ret == -1)
	{
		perror("execv error");
		exit(1);
	}



	return 0;
}
