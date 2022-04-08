/*
1.先分配3个结构体指针数组
2.每个结构体中含一级指针
3.每一个一级指针含一块堆内存

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUM 3

typedef struct Person
{
    char *name;
    int age;
}MP;

MP ** Myalloc(int num)
{
    if(NUM <= 0)
        return NULL;
    
    MP ** MyPerson = malloc(sizeof(MP*) * NUM) ;
    if(MyPerson == NULL)
        return NULL;

    for(int i = 0;i<NUM;++i)
    {
        MyPerson[i] = malloc(sizeof(MP)) ;
        if(MyPerson[i] == NULL)
            return NULL;
        MyPerson[i]->name = malloc(sizeof(char) * 64) ;
        if(MyPerson[i]->name == NULL)
            return NULL;
        memset(MyPerson[i]->name,0,64) ;
    }
    return MyPerson;
}
void MyContext(MP**p,int len)
{
    if(p ==NULL)
        return ;
    for(int i = 0;i<len;++i)
    {
        sprintf(p[i]->name,"Name_%d",i+1);
        p[i]->age = 20+i;
    }
}
void show(MP ** p,int len)
{
    if(p ==NULL)
        return ;
    for(int i = 0;i<len;++i)
    {
        printf("name:%s\tage:%d\n",p[i]->name,p[i]->age) ;
    }
}

void MyFree(MP** p,int len)
{
    if(p ==NULL)
        return ;
    for(int i = 0;i<len;++i)
    {
        if(p[i] == NULL)
            continue ;
        if(p[i]->name != NULL)
        {
            free(p[i]->name);
            p[i]->name = NULL ;
        }
    }
    for(int i = 0;i<len;++i)
    {
        if(p[i] != NULL)
        {
            free(p[i]);
            p[i] = NULL ;
        }
    }
    free(p) ;
    p = NULL ;
}

int main(void)
{
    MP ** p= Myalloc(NUM) ;
    if(p == 0)
        perror("malloc fail") ;
    MyContext(p,NUM);
    show(p,NUM);
    MyFree(p,NUM);

    

    return  0 ;
}
