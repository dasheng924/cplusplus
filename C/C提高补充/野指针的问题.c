#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//指针变量和指针变量指向的内存区域是两个不同的概念

int main(void)
{

    char *p = NULL;
    p = (char *)malloc(100);
    if (p == NULL)
    {
        return -1;
    }

    stpcpy(p, "1234");
    puts(p);

    if (p != NULL)
    {
        free(p);
        p = NULL;
    }

    //释放一次后,再次去释放一次

    if (p != NULL)
    {
        free(p);
    }

    return 0;
}