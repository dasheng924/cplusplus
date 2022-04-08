#include <iostream>
using namespace std;

//委托构造函数：构造函数调用构造函数
class Test
{
public:
    Test(){}
    Test(int max)
    {
        m_max = max>100?max:100;
    }
    Test(int max,int min):Test(max) //委托构造函数
    {
        m_min = min>0?min:1;
    }
    Test(int max,int middle,int min):Test(max,min)
    {
        m_middle = 50;
    }

private:
    int m_min;
    int m_middle;
    int m_max;
};

//继承构造函数
class Base{
public:
    Base(int a,int b){
        m_a = a;
        m_b = b;
    }

    void func(int a)
    {
        cout<<"Base func(int a)"<<endl;
    }
    void func(int a,int b)
    {
        cout<<"Base func(int a,int b)"<<endl;
    }

    int m_a;
    double m_b;
};

class Child: public Base
{
public:
    using Base::Base; //继承构造函数,可以使用基类的所有构造函数
    using Base::func;//
    void func()
    {
        cout<<"Child func()"<<endl;
    }

};

int main()
{
    Child c(22,13.123);
    cout<<c.m_a<<"\t"<<c.m_b<<endl;

    c.func();
    c.func(10);
    c.func(1,10);
}

//聚合类型：数组；无基类，无虚函数，无自定义构造函数，无私有成员或者受保护非静态成员
//非聚合类型：需要提供对应的构造函数