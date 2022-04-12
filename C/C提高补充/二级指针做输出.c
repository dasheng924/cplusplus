#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStr(char **p1 /*out*/, int *len1 /*out*/, char **p2 /*out*/, int *len2 /*out*/)
{
    if (p1 == NULL || p2 == NULL || len1 == NULL || len2 == NULL)
        return -1;

    char *tmp = (char *)malloc(100);
    if (tmp == NULL)
        return -2;
    strcpy(tmp, "hel3ddddddddddlo");
    *len1 = strlen(tmp);
    *p1 = tmp;

    char *tmp2 = (char *)malloc(100);
    if (tmp2 == NULL)
        return -2;
    strcpy(tmp2, "wordeddeld");
    *len2 = strlen(tmp2);
    *p2 = tmp2;

    return 0;
}

int strFree(char **p)
{
    if (p == NULL)
        return -1;

    char *tmp = *p;
    if (tmp != NULL)
    {
        free(tmp);  //释放指针指向的内存空间
        tmp = NULL; //指针变量本身置0
    }

    return 0;
}

int strFree2(char *p)
{
    if (p == NULL)
    {
        return -1;
    }

    free(p);
    //释放不了指针变量的本身,有野指针现象
    // p = NULL; // char *p  = NULL; 和这个是一样的意思,这个是改变不了main中myP1的值的

    return 0;
}

int main(void)
{

    char *myP1 = NULL;
    char *myP2 = NULL;
    int myLen1 = 0;
    int myLen2 = 0;

    int ret = getStr(&myP1, &myLen1, &myP2, &myLen2);
    if (ret != 0)
    {
        printf("func getStr() error:%d\n ", ret);
        return ret;
    }

    printf("myP1:%s,len:%d\n", myP1, myLen1);
    printf("myP2:%s,len:%d\n", myP2, myLen2);

    strFree(&myP1);
    strFree(&myP2);

#if 0
    strFree2(myP1);
    myP1 = NULL;
    strFree2(myP2);
    myP2 = NULL;

#endif
    return ret;
}