/*************************************************************************
	> File Name: exec_ps.c
	> Created Time: 二  3/ 3 19:14:35 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid > 0)
	{
		sleep(1);
		printf("parent\n");
	}
	else
	{
		int fd = open("ps.txt",O_RDWR | O_CREAT,0665);
		if(fd == -1)
		{
			perror("open fail");
			exit(1);
		}
		int ret = dup2(fd,1);

		if(execlp("ps","ps","aux",NULL) == -1)
		{
			perror("execlp fail");
			exit(1);
		}

		close(fd);

	}


	return 0;
}
