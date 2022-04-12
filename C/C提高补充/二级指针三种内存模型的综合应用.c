#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(char **p1, int len1, char (*p2)[20], int len2, char ***p3, int *len3)
{
    char **tmp = NULL;
    int tmpLen = 0;

    tmp = (char **)malloc(sizeof(char *) * (len1 + len2));
    if (tmp == NULL)
        return -1;

    int i = 0;
   
    for (; i < len1; ++i)
    {
        tmpLen = strlen(p1[i]) + 1;
        tmp[i] = (char *)malloc(sizeof(char) * tmpLen);
        if (tmp[i] == NULL)
            return -1;
        strcpy(tmp[i], p1[i]);
    }
    
    for (int j = 0; j < len2;j++,i++)
    {
        tmpLen = strlen(p2[j]) + 1;
        tmp[i] = (char *)malloc(sizeof(char) * tmpLen);
        if (tmp[i] == NULL)
            return -1;
        strcpy(tmp[i], p2[j]);
    }

    //排序
    tmpLen = len1 + len2;

    for (int i = 0; i < tmpLen; ++i)
    {
        for (int j = i + 1; j < tmpLen; ++j)
        {
            if (strcmp(tmp[i], tmp[j]) > 0)
            {
                char *t = tmp[i]; //交换的是指针
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
        }
    }

    *p3 = tmp; //传出结果
    *len3 = len1+len2;

    return 0;
}

int freeSort(char **p, int len) //这个p指向了第三块内存空间
{
    if (p == NULL) //这里判断的是指针的值
        return -1;
    for (int i = 0; i < len; ++i)
    {
        if (p[i] != NULL)
        {
            free(p[i]); //释放的是一级指针挂的内存
        }
    }
    free(p); //释放的是堆上分配的里面含有指针的那块内存
    //没有把指针变量进行释放

    return 0;
}

int freeSort2(char ***p, int len) //把二级指针指向的二维内存释放掉了,也把指针变量置为NULL
{
    if (p == NULL)
        return -1;
    char **tmp = NULL;
    tmp = *p; //还原成二级指针
    if (tmp == NULL)
        return -1;
    for (int i = 0; i < len; ++i)
    {
        free(tmp[i]);
    }
    free(tmp);
    *p = NULL; //这个释放掉了指针变量的内存
    return 0;
}

void show(char ***p, int len)
{
    if (p == NULL)
        return;
    
    char **tmp = NULL;
    tmp = *p;
    if(tmp == NULL)
        return;
    for (int i = 0; i < len; ++i)
    {
        printf("%s\n", tmp[i]);
    }
}

int main(void)
{
    //第1和第2种内存中的数据拷贝到第三种内存中
    //第一种二级指针模型
    char *pp1[] = {"aaa", "ddd", "ccc"};
    //第二种二级指针模型
    char buf[3][20] = {"111", "333", "222"};
    //第三种内存模型
    char **pp3 = NULL;

    int len1 = sizeof(pp1) / sizeof(*pp1);
    int len2 = 3;
    int len3 = 0;
    int ret = 0;

    ret = sort(pp1, len1, buf, len2, &pp3, &len3);
    if (ret != 0)
    {
        printf("soft() error:%d\n", ret);
        return ret;
    }

    show(&pp3, len3);

    freeSort2(&pp3, len3);

    return ret;
}
