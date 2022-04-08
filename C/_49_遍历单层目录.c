/*
如果只遍历单层目录是不需要递归的，按照上边介绍的函数的使用方法，依次继续调用即可。
假设我们需要得到某个指定目录下 txt 格式文件的个数，示例代码如下


*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(int argc,char *argv[])
{
    //open dir
    DIR * dir = opendir(argv[1]);
    if(dir == NULL)
    {
        perror("未找到要打开的文件夹！") ;
        return -1;
    }

    //遍历目录
    int count = 0;

    while(1)
    {   
        struct dirent * ptr = readdir(dir) ;
        if(ptr == NULL)
        {
            //perror("目录读完了!") ;
            break ;
        }
        //读到一个文件，判断文件的类型
        if(ptr->d_type == DT_REG)
        {
            char *p = strstr(ptr->d_name,".txt") ;
            if( p != NULL && *(p+4) == '\0')
            {
                count++;
                printf("%d -->%s\n",count,ptr->d_name) ;
            }
        }
    }

    printf("%s 文件夹中共有txt文件%d个。\n",argv[1],count) ;

    //关闭目录
    closedir(dir) ;







    return 0;
}