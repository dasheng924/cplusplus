#include <iostream>

using namespace std;

//1 .原有的构造函数，析构函数，operator= 都是不能被继承的，因为这些都是当前类用来初始化和资源回收的，
//在派生类中，这些初始化和清理工作肯定是不一样的，这些函数只局限与特定的类层次

//2，友元函数不能被继承，因为友元不属于类（友元特点：不具有传递性 和 交换性）

//3，静态成员的继承是OK的，看 _30_




class A
{
public:
    //A(){cout<<"A constructor"<<endl;}
    A(int a){m_a = a;cout<<"A constructor"<<endl;}
    ~A(){cout<<"A destruction"<<endl; }


    int m_a ;
};

class B:public A
{
public:
    //当父类有有参构造时，子类需要提供初始化列表来初始化父类的属性
    B(int num):A(num){cout<<"B construction"<<endl ;} 
    ~B(){cout<<"B destruction"<<endl ;}

};

int main()
{   
    B b1(100);

    cout<<"sizeof(b1) = "<<sizeof(b1)<<endl ;
    


    return 0; 
}

/* 构造和析构的顺序
A constructor
B construction
sizeof(b1) = 4
B destruction
A destruction

父类构造--》子类构造--》子类析构---》父类析构




*/

/*
1.父类构造--》子类构造--》子类析构---》父类析构
2.当父类构造函数有参数时，必须显式的调用父类的规则函数，且用列表初始化
C++11 中可以使用继承构造 using Base::Base;

*/