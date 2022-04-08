#include <iostream>

using namespace std;

/*
    1.成员变量和成员函数是分开存储的
    2.类的大小受 非静态成员变量的影响，同时和字节对齐也是有关系的

    3成员函数和静态成员 不算在对象所占的大小里
*/

/*add 
1.当一个类中只有非static变量的时候，类的大小和这些变量息息相关
2.普通的函数不占类的空间，会放到代码区
3.有虚函数的时候，会在内存中生成一个虚函数表指针，指向一个函数指针数组（虚函数表）
这个指针就会占大小，多个虚函数就只会有一个虚函数表指针。




*/


class Test
{

public:
    int a;
    void func(void){}
    double b;
    const static int c  = 10;


};

void test()
{
    cout<<"sizeof(Test):"<<sizeof(Test)<<endl;

}

int main(void)
{
    
    test();

    return 0;
}


