#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

/*
关于变量 st_mode: 
- st_mode -- 16位整数
	○ 0-2 bit -- 其他人权限
		- S_IROTH    00004  读权限   100
		- S_IWOTH    00002  写权限   010
		- S_IXOTH    00001  执行权限  001
		- S_IRWXO    00007  掩码, 过滤 st_mode中除其他人权限以外的信息
	○ 3-5 bit -- 所属组权限
		- S_IRGRP    00040  读权限
		- S_IWGRP    00020  写权限
		- S_IXGRP    00010  执行权限
		- S_IRWXG    00070  掩码, 过滤 st_mode中除所属组权限以外的信息
	○ 6-8 bit -- 文件所有者权限
		- S_IRUSR    00400    读权限
		- S_IWUSR    00200    写权限
		- S_IXUSR    00100    执行权限
		- S_IRWXU    00700    掩码, 过滤 st_mode中除文件所有者权限以外的信息
	○ 12-15 bit -- 文件类型
		- S_IFSOCK   0140000 套接字
		- S_IFLNK    0120000 符号链接（软链接）
		- S_IFREG    0100000 普通文件
		- S_IFBLK    0060000 块设备
		- S_IFDIR    0040000 目录
		- S_IFCHR    0020000 字符设备
		- S_IFIFO    0010000 管道
		- S_IFMT     0170000 掩码,过滤 st_mode中除文件类型以外的信息
			
############### 按位与操作举例 ###############			
    1111 1111 1111 1011   # st_mode
    0000 0000 0000 0100   # S_IROTH
&
----------------------------------------
    0000 0000 0000 0000   # 没有任何权限
    






*/

int main(void)
{
    //获取文件的大小
    struct stat my_stat;
    //int stat(const char *pathname, struct stat *buf);
    char filename[64] = "new.txt" ;
    int ret = stat(filename,&my_stat) ;
    if(ret == -1)
    {
        perror("stat file fail!");
        return -1;
    }

    unsigned int length = my_stat.st_size;
    printf("%s的字节数为%u,大小为%ukb\n",filename,length,length/1024) ;

    if(S_ISREG(my_stat.st_mode))
    {
        puts("这是一个普通文件!");
    }
   // 文件所有者对文件的操作权限
    printf("文件所有者对文件的操作权限: ");
    if(my_stat.st_mode & S_IRUSR)
    {
        printf("r");
    }
    if(my_stat.st_mode & S_IWUSR)
    {
        printf("w");
    }
    if(my_stat.st_mode & S_IXUSR)
    {
        printf("x");
    }
    printf("\n");


    //获取时间
    time_t second = time(NULL) ;
    printf("自 1970-01-01 起的小时数 = %ld\n",second/3600) ; //返回的是秒数
    char * p = ctime(&second);  //转为正常的字符串
    puts(p) ;







    return 0;
}