#include <iostream>

using namespace std;

class Person
{
public:
    static int a; //定义
    int c;
    const static int d  = 100  ;//静态常量最好在类中初始化


private:
    static int b;

public:
    static void func()  //静态成员函数只可以访问静态成员
    {
        cout<<a<<endl;
    }
    void func1()    //非静态成员函数可以访问静态成员变量和非静态变量
    {
        cout<<a<<endl;
        cout<<c<<endl;

    }


};


//初始化，必须在类外初始化
int Person::a = 10;
int Person::b = 20 ;

int main(void)
{
    Person p;
    //方法1:
    cout<<Person::a<<endl;  //static 成员变量也有访问控制的约束

    //方法2:
    cout<<p.a<<endl;


    cout<<p.d<<endl;

    return 0;
}

