#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(char **p, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%s ", p[i]);
    }
}

void sort(char **pp, int len)
{
    if (pp == NULL)
        return;
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (strcmp(pp[i], pp[j]) < 0)
            {
                char *tmp = NULL;
                tmp = pp[i];
                pp[i] = pp[j];
                pp[j] = tmp;
            }
        }
    }
}

void sort2(char **pp, int len)
{
    if (pp == NULL)
        return;
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (strcmp(pp[i], pp[j]) < 0)
            {
                char tmp[100];
                strcpy(tmp, pp[i]);
                strcpy(pp[i], pp[j]);
                strcpy(pp[j], tmp);
            }
        }
    }
}

//构造出自己的内存模型

int getMem(char ***p /*out*/, int len /*in*/)
{
    char **tmp = NULL;

    if (p == NULL) //也就是指针变量P的值是空值的话,它后面是不跟内存的
    {
        return -1;
    }

    tmp = (char **)malloc(sizeof(char *) * len);
    if (tmp == NULL)
    {
        return -1;
    }

    for (int i = 0; i < len; ++i)
    {
        tmp[i] = (char *)malloc(sizeof(char) * 100);
        if (tmp[i] == NULL)
            return -1;
        sprintf(tmp[i],"%d%d%d",i,i,i);
    }
    *p = tmp;

    return 0;
}

int freeMem(char ***p, int len)
{
    if (p == NULL)
        return -1;

    char **tmp = *p;
    for (int i = 0; i < len; ++i)
    {
        if (tmp[i] != NULL)
        {
            free(tmp[i]); //释放掉挂的一维的内存空间
        }
    }
    free(tmp); //二维整个空间释放
    *p = NULL; //把实参置为NULL

    return 0;
}

int main(void)
{

    //先在堆上分配空间,用来放指针

    int num = 5;
    // char **pp = (char **)malloc(sizeof(char *) * num);
    // if (pp == NULL)
    //     return -1;

    // for (int i = 0; i < num; ++i)
    // {
    //     pp[i] = (char *)malloc(sizeof(char) * 20);
    //     if (pp[i] == NULL)
    //         return -1;
    //     sprintf(pp[i], "%d%d%d", i, i, i);
    // }

    char **pp = NULL;
    getMem(&pp, num);

    // //show
    // for(int i = 0;i<num;++i)
    // {
    //     printf("%s ",pp[i]);

    // }

    show(pp, num);
    printf("\n");

    sort2(pp, num);
    show(pp, num);
    printf("\n");

    freeMem(&pp, num);

    // // free
    // for (int i = 0; i < num; ++i)
    // {
    //     if (pp[i] != NULL)
    //     {
    //         free(pp[i]);
    //         pp[i] = NULL;
    //     }
    // }

    // for (int i = 0; i < num; ++i)
    // {
    //     if (pp != NULL)
    //     {
    //         free(pp);
    //         pp = NULL;
    //     }
    // }

    return 0;
}
