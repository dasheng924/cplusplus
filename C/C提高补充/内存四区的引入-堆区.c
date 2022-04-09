#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//堆
char *getStr1(int num)
{   
    char *p = malloc(sizeof(char)*num);
    if(p == NULL)
    {
        return NULL;
    }

    return p;
}

//栈
char *getStr1(int num)
{   
    char buf[64];
    strcpy(buf,"123");
    return buf; //err,返回临时变量的地址  
}



int main(void)
{

    char *p1  = getStr1(10);
    strcpy(p1,"hello"); //往指针指向的内存空间里面放入数据

    printf("p1 = %s\n",p1);//打印p1指向内存空间存储的值
    printf("p1 = %d\n",p1); //打印p1的值

    return 0;
}