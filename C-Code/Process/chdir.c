/*************************************************************************
	> File Name: chdir.c
	> Created Time: 五  2/28 21:14:51 2020
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	if (argc < 2)
	{
		printf("input is not ok\n");
		exit(1);
	}

	int ret = chdir(argv[1]);
	if(-1 == ret)
	{
		perror("change dir fail");
		exit(1);
	}
	
	//获取当前的工作目录
	char buf[128];
	getcwd(buf,sizeof(buf));
	printf("current dir:%s\n",buf);

	return 0;
}

