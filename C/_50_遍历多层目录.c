#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>


int getTxtNum(const char * filedir)
{
    if(filedir == NULL)
    {
        perror("传入的文件路径错误!");
        return -1;
    }
    DIR * dir = opendir(filedir) ;
    if(dir  == NULL)
    {
        perror("open dir fail!");
        return -1;
    }

    struct dirent * ptr = NULL;

    int count = 0;

    while(NULL != (ptr=readdir(dir)))
    {
        //如果是目录 . ..不处理
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..") == 0)
        {
            continue;
        }
        //读到的是目录
        if(ptr->d_type == DT_DIR)
        {
            //目录
            char newPath[64];
            sprintf(newPath,"%s/%s",filedir,ptr->d_name);
            //读取目录的子目录
            count+=getTxtNum(newPath) ;
        }
        else if(ptr->d_type == DT_REG)
        {
            //普通文件
            char * p = strstr(ptr->d_name,".txt");
            if(p != NULL && *(p+strlen(".txt")) == '\0')
            {
                count++;
                printf("%d--->%s\n",count,ptr->d_name);
            }

        }

    }

    closedir(dir) ;
    return count;
}



int main(int argc,char *argv[])
{
    if(argc <0 && argc >2 )
    {
        printf("input error!\n");
        return -1;
    }

    int ret = getTxtNum(argv[1]);
    if(ret == -1)
    {
        printf("获取txt文件数量失败！") ;
        return -1;
    }
    printf("%s的文件夹下txt文件的数量为:%d\n",argv[1],ret) ;


    return 0 ;
}