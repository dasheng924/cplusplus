/*************************************************************************
	> File Name: ftruncate.c
	> Created Time: 五  3/ 6 01:39:06 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("test_ftruncate.txt",O_RDWR |O_CREAT,0644);
	if(fd == -1)
	{
		perror("open fail");
		exit(1);
	}


	int ret = ftruncate(fd,10);
	if(ret == -1)
	{
		perror("ftruncate fail");
		exit(1);
	}

	struct stat  st;
	int ret_stat = fstat(fd,&st);
	printf("ftruncate size:%lld\n",st.st_size);
	printf("ftruncate mode :%lo\n",(unsigned long )st.st_mode);


	char * str= "happy dayday";
	int ret_write = write(fd,str,strlen(str));
	if(ret_write == -1)
	{
		perror("write fail");
		exit(1);
	}



	close(fd);


	return 0;
}
