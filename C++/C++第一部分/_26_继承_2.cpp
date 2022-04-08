#include <iostream>

using namespace std;

/*
不管何种继承方式，原本是私有的，继承都是不可访问

原本是公有的，和继承方式保持一样


原本是保护的，除了私有继承都是保护




*/




class A
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

//public 
class B1:public A
{
    void func()
    {
       // cout<<c<<endl ; // 私有属性继承不可访问
       cout<<a<<endl ;//可以继承，属性为public
       cout<<b<<endl ;//可以继承，属性为proteed,类外不可访问

    }
};

//protected
class B2:protected A
{
    void func()
    {
       // cout<<c<<endl ; // 私有属性继承不可访问
       cout<<a<<endl ;//可以继承，属性为protected,类外不可访问
       cout<<b<<endl ;//可以继承，属性为proteed,类外不可访问
    }
};

//private:
class B3:private A
{
    void func()
    {
       // cout<<c<<endl ; //不可以继承     
       //cout<<a<<endl ;//不可以继承
       //cout<<b<<endl ;//不可以继承
    }
};


/*
cl /d1 reportSingleClassLayout类名 所属cpp文件 

*/

//子类把父类的所有成员都继承了，只是通过继承方式 让一些不显示