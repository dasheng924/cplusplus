#include <stdio.h>

char *getStr1()
{   
    char *p = "abcd";

    return p;
}


char *getStr2()
{   
    char *p = "abcd";

    return p;
}


int main(void)
{

    char *p1  = getStr1();
    char *p2 = getStr2();

    printf("p1 = %s,p2 = %s\n",p1,p2);//打印p1,p2指向内存空间存储的值
    printf("p1 = %d,p2 = %d\n",p1,p2); //打印p1,p2的值

    return 0;
}