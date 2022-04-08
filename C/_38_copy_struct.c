#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Teacher
{
    char * name;
    int age;
}Tea;


void test01()
{
    Tea t1,t2;
    t1.name = malloc(sizeof(char) * 32) ;
    memset(t1.name,0,32) ;
    strcpy(t1.name,"alex") ;
    t1.age = 22 ;

    t2.name = malloc(sizeof(char) * 64) ;
    memset(t2.name,0,32) ;
    strcpy(t2.name,"Lucy2") ;
    t2.age = 24 ;

    //t1 = t2 ;
    /*
    1.结构体中含有指针，并且在堆上分配内存，就需要注意结构体拷贝的问题
    2.普通的结构体拷贝就是每一个字节的对应拷贝
    3.问题1:存在内存泄露的问题，t1 中name指定的堆内存会被泄露
    4.问题2:存在同一块内存被释放两次的问题
    */
   //手动构建结构体赋值
   //1.清理t1.name
   if(t1.name != NULL)
   {
       free(t1.name);
       t1.name = NULL ;
   }
   //2.重新分配内存
   unsigned int len = strlen(t2.name) ;
   //printf("%u\n",len) ; 
   t1.name = malloc(sizeof(char) * (len+1) );   //分配的空间要多加1
   memset(t1.name,0,len+1) ; 
   //3.拷贝
   strcpy(t1.name,t2.name) ;
   t1.age = t2.age ;

   printf("name:%s age:%d\n",t1.name,t1.age) ;
   printf("name:%s age:%d\n",t2.name,t2.age) ;


    if(t1.name != NULL)
    {
        free(t1.name) ;
        t1.name =  NULL ;
    }
    if(t2.name != NULL)
    {
        free(t2.name) ;
        t2.name = NULL ;
    }











}





int main(void)
{

    test01() ;



    return 0; 
}