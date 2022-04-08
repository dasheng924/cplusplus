#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{   
    int fd = open("./test.c",O_RDWR|O_CREAT,0664) ;
    printf("%d\n",fd) ;
    if(fd == -1)
    {
        perror("open file fail!");
    }

    char buf[64] = "defefefwef";
    int ret = write(fd,buf,strlen(buf));
    if(ret > 0)
    {
        printf("写入的字符数为:%d\n",ret) ;
    }




    close(fd) ;




    return 0;
}
