#include <stdio.h>


void func()
{
    printf("hello world!\n") ;
}

void test01()
{
    typedef void (MYFUNC_TYPE)() ;

    //1.先定义函数类型，再通过类型定义指针
    MYFUNC_TYPE * pFunc = func; 

    pFunc(); //编译器会自动帮你解引用
    (*pFunc)();
}

void test02()
{
    typedef void (* MYFUNC_TYPE2)();
    MYFUNC_TYPE2 pFunc2 = func ;
    pFunc2() ;
    (*pFunc2)();
}

void test03()
{

#if 0
    void (*MYFUNC_TYPE3)() = void(*)() NULL;  //把NULL 转化为函数指针类型
    MYFUNC_TYPE3 = func;
    MYFUNC_TYPE3();
#endif

    void (*MYFUNC_TYPE3)() = func;

    MYFUNC_TYPE3();
    (*MYFUNC_TYPE3)();
    
}


int main(void)
{
    //test01() ;
    //test02();
    test03() ;


    return  0 ;
}