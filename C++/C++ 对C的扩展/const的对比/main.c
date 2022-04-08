#include <stdio.h>
int main(void)
{
    extern const int num ;
    printf("num = %d\n",num) ;
    return 0;
}

/*
1.const int num = 100 ;这种是不会分配内存的，但对其取地址时 是会分配临时内存

const int aa = 100 ;
int *p = (int*)&aa ; //此时取地址，会分配临时内存

2.用extern修饰时会分配内存

3.用已有变量初始化const 变量

int a1 = 100 ;
const int a = a1 ;//分配内存

//4.自定义数据类型，会分配内存
struct Person{
    string name ;
    int age ;
};
const Person p ;  //分配内存，可以修改

Person * p = (Person *) &p ;
 //通过p可以修改数据








*/