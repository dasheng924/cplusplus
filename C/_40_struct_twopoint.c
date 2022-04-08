/*
1.构造3个结构体指针的数组
2.每一个结构体中含有char * name 和 char** students
3.char * name 需要分配64字节的堆空间 ，char **students 需要分配char * 的数组
4.char * 的数组 需要分配对应的堆空间

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define T_NUM 3
#define S_NUM 5

typedef struct Teacher
{
    char * name;
    char ** students;
}MT;

//int MyMalloc(MT ***p) ;

MT **MyAlloc()
{
    MT ** p = malloc(sizeof(MT*) * T_NUM) ;
    if(p == NULL)
        return NULL ;
    for(int i = 0;i<T_NUM ;++i)
    {
        p[i] = malloc(sizeof(MT));
        if(p[i] == NULL)
            return NULL ;
        p[i]->name = malloc(sizeof(char) * 64) ;
        if(p[i]->name == NULL)
            return NULL;
        memset(p[i]->name,0,64) ;
        p[i]->students = malloc(sizeof(char *) * S_NUM );
        if(p[i]->students == NULL)
            return NULL;
        for(int j = 0;j<S_NUM;++j)
        {
            p[i]->students[j] = malloc(sizeof(char) * 64) ;
            if(p[i]->students[j] == NULL)
                return NULL ;
            memset(p[i]->students[j],0,64) ;
        }
    }
    return p;
}

void MyContext(MT **p)
{
    if(p == NULL)
        return ;
    for(int i  =0;i<T_NUM;++i)
    {
        sprintf(p[i]->name,"Teacher_%d",i+1);
        for(int j = 0;j<S_NUM;++j)
        {
            sprintf(p[i]->students[j],"%s_Stu_%d",p[i]->name,j+1);
        }
        
    }
}

void show(MT ** p)
{
    if(p == NULL)
        return ;
    for(int i  =0;i<T_NUM;++i)
    {
        printf("\n");
        printf("%s\n",p[i]->name);
        for(int j = 0;j<S_NUM;++j)
        {
            printf("%s\t",p[i]->students[j]);
        }
    }
}


void MyFree(MT ** p)
{
    if(p == NULL)
        return;
    for(int i = 0;i< T_NUM;++i)
    {
        if(p[i] == NULL)
            continue ;
        for(int j = 0;j<S_NUM;++j)
        {
            if(p[i]->students[j] != NULL)
            {
                free(p[i]->students[j]);
                p[i]->students[j] = NULL;
            }
        }
        if(p[i]->name != NULL)
        {
            free(p[i]->name);
            p[i]->name = NULL;
        }
        if(p[i] != NULL)
        {
            free(p[i]);
            p[i] = NULL;
        }
    }
    free(p);
    p = NULL ;
}


int main(void)
{
    MT** mt = MyAlloc();
    if(mt == NULL)
        perror("malloc fail") ;
    MyContext(mt);
    show(mt);
    free(mt);
    return 0;
}