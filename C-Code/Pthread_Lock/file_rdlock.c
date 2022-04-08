#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
	int fd = open("file_lock_test",O_RDWR);
	if(fd == -1)
	{
		perror("open file error");
		exit(1);
	}

	struct flock f;
	f.l_type = F_RDLCK;
	f.l_whence = SEEK_SET;
	f.l_start = 0;
	f.l_len = 100;

	int ret = fcntl(fd,F_SETLKW,&f);
	if(ret == -1)
	{
		perror("rd lock fail");
	}
	else
	{
		printf("rd lock ok!\n");
	}
	sleep(10);
	close(fd);

	

	return 0;
}