#include <iostream>
using namespace std ;

//C++ 中对函数的默认参数
//声明的时写了默认参数的值，在函数的实现时就不要写默认值
void func(int a ,int b = 10,char c = 'c');

void test01()
{
    func(10);
    func(1,2);
    func(1,2,'a');
}

//C++ 的占位参数
//不能使用占位的哪一位参数




int main(void)
{
    //test01();
    return 0;
}


inline void  func(int a,int b,char c)
{
    cout<<"a+b = "<<a+b<<"\t"<<"c = "<<c<<endl ;
}

