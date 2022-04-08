/*
使用 fcntl () 复制文件描述符，函数返回值为新分配的文件描述符
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{   

    //先打开已经存在的文件
    char * filename = "new.txt";
    int ret_open = open(filename,O_RDWR);
    if(ret_open == -1)
    {
        perror("open fail!") ;
        return -1;
    }

    //对于已经打开的文件，修改文件的属性
    int flag = fcntl(ret_open,F_GETFL) ;
    flag |= O_APPEND ;
    fcntl(ret_open,F_SETFL,flag) ; //设置完之后，文件就会写到最后




    char * str = "hello ,world" ;
   // lseek(ret_open,0,SEEK_END);


    int num = write(ret_open,str,strlen(str)) ;
    if(num == -1)
    {
        perror("old write fail!");
        return -1;
    }

    int new_fd = fcntl(ret_open,F_DUPFD) ;
    if(new_fd == -1)
    {
        perror("fcntl copy fd fail!");
        return -1;
    }
    printf("new fd = %d\n",new_fd) ;
    close(ret_open) ;

    lseek(new_fd,0,SEEK_END);
    char *str2 = "加油 骚年！";
    write(new_fd,str2,strlen(str2));
    close(new_fd) ;


    return 0;
}