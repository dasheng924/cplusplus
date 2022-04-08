#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{

    int fd_r = open("./fifotest",O_RDONLY);
    if(fd_r == -1)
    {
        perror("open fifotest error!");
        exit(-1);
    }
    //循环读取
    
    char buf[4096];
    while (1)
    {
        memset(buf,0,sizeof(buf));
        int ret = read(fd_r,buf,sizeof(buf));
        if(ret == 0)
        {
            printf("已经读完，阻塞解除！\n");
            break;
        }
        printf("%s--->%d\n",buf,ret);
        
    }
    close(fd_r);

    exit(0);
}