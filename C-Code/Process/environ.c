/*************************************************************************
	> File Name: environ.c
	> Created Time: 日  3/ 8 00:47:47 2020
 ************************************************************************/
#include <stdio.h>
extern char **environ;

int main(void)
{
	int i = 0;
	for(i = 0;environ[i];i++)
		printf("%s\n",environ[i]);


	return 0;
}
