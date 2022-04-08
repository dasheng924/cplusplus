//假设有一个比较大的磁盘文件，打开这个文件得到文件描述符 fd1，
//然后在创建一个新的磁盘文件得到文件描述符 fd2, 在程序中通过 fd1 将文件内容读出，并通过 fd2 将读出的数据写入到新文件中


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    //先打开原始的文件
    int fd1 = open("old.txt",O_RDONLY) ;
    if(fd1 == -1)
    {
        perror("open old file fail!");
        return -1;
    }

    int fd2 = open("new.txt",O_RDWR|O_CREAT,0664);
     if(fd2 == -1)
    {
        perror("open new file fail!");
        return -1;
    }

    char buf[4096];

    int ret;
    int i = 1;
    while((ret = read(fd1,buf,sizeof(buf))))
    {
        write(fd2,buf,ret);
        i++;
        printf("第%d次进行拷贝！",i);
    }

    close(fd1);
    close(fd2);

    return 0;
}


