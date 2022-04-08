/*
1.同名成员变量，直接调用的是子类的；父类需要显式的使用作用域或者子类中提供接口
2.同名的成员函数，直接调用是子类的；
如果子类没有对应的函数，肯定调用的是父类的；
需要调用父类的成员函数，就需要使用作用域；
任何时候重新定义基类中的一个重载函数，在新类中所有的其他版本将被自动隐藏.

//1.子类会继承父类的同名函数
//2.子类有和父类同名的函数，会发生隐藏，需要显式指定作用域调用父类的同名函数

*/
#include <iostream>
using namespace std;

class A
{
public:
    A(int a):m_a(a){}
    void func(){cout<<"A cons"<<endl ;}
    void func(int v){cout<<"A cons(int v)"<<endl ;}
    
    int m_a;
};
class B:public A
{
public:
    B(int a1,int a2):m_a(a1),A(a2){}
    //void func(){cout<<"B cons"<<endl ;}
    int m_a;
};

class B2:public A{
public:
    void func(int a,int b){
        cout<<a<<"\tb"<<endl;
    }
};

void test01()
{
    //取到子类的成员变量和成员函数
    B b(1,2);
    cout<<"B m_a ="<<b.m_a<<endl;
    b.func();
    cout<<"------------------------------"<<endl ;
    //取到父类的成员变量和成员函数
    cout<<"A m_a = "<<b.A::m_a<<endl ;
    b.A::func();
    cout<<"------------------------------"<<endl ;
    b.A::func(1);


}

int main()
{
    test01();

    return 0;
}