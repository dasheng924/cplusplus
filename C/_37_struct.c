#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
struct Person
{
    char name[32] ;
    int age ;

}p= {"name",23} ; //直接在这里进行初始化

struct  //匿名结构体
{
    char name[32] ;
}p1;

typedef struct MyPerson //直接起别名
{
    int age ;
}mp;

void test2()
{
    strcpy(p1.name,"alex") ;
    printf("%s\n",p1.name) ;
}

void test3()
{
    //mp p3 = {24} ;
    mp p3 ;
    p3.age  = 99 ;
    printf("age = %d\n",p3.age) ;
}

#endif

#if 0

    //结构体数组
    typedef struct Stu
    {
        char name[32];
        int age ;
    }MyStu;

    void show(MyStu ms[],int len)
    {
        for(int i = 0;i<len;++i)
        {
            printf("name :%s\t\tage :%d\n",ms[i].name,ms[i].age);
        }
        printf("\n");
    }

    MyStu s[5]  = {
        {"alex",23},
        {"lucy",34},
        {"Occ",12},
        {"YanYan",56},
        {"KmK",45}
    };

void test04()
{
    show(s,sizeof(s)/sizeof(MyStu)) ;
}

#endif



int main(void)
{

    // test2();
    // test3() ;
    // test04() ;



#if 1
//在堆上分配结构体数组
 //结构体数组
struct Stu
{
    char name[32];
    int age ;
};

struct Stu * ps = malloc(sizeof(struct Stu) * 5) ; 
//这个定义在全局的时候报错，因为全局变量的值要在编译期间就确定，malloc分配的内存，需要在运行时才确定
/* https://blog.csdn.net/weixin_38167363/article/details/101657619*/

for(int i = 0;i<5;++i)
{
    sprintf(ps[i].name,"name_%d",i+1) ;
    ps[i].age = 23+i;
};


 for(int i = 0;i<5;++i)
{
    printf("name :%s\t\tage :%d\n",ps[i].name,ps[i].age);
}
printf("\n");




#endif


    return 0;
}