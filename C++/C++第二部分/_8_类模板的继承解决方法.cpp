#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Person
{
public:
    Person(T age)
    {
        this->m_age = age;
    }

    virtual void show(){
        cout<<"Person age="<<this->m_age<<endl;
    }

    T m_age;
};



//1.必须要显式的指定继承的类型，这样基类才能调用构造函数分配正确的内存

//继承派生到普通类

class Child:public Person<int>  //指定类型继承
{
public:

    // Child(int var1):Person<int>(100)
    // {
    //     this->m_aage = var1;
    // }
    Child(int var1,int var2):Person<int>(var1) //指定类型初始化
    {
        this->m_aage = var2;
    }

    virtual void show(){
        cout<<"Child age="<<this->m_aage<<endl;
    }

    int m_aage;
};






//继承派生到类模板
template<class T1>
class Child2:public Person<int>
{
public:
    Child2(int var):Person<int>(100)
    {
        this->m_a = var;
    }

    virtual void show(){
        cout<<"Child2 age="<<this->m_a<<endl;
    }

    T1 m_a;
};


// //这样是用模板函数做函数参数
//整体进行模板化
// template<typename T>
// void doWork(T &p)
// {
//     p.show();
// }


template<typename T>
void doWork(Person<T> &p) //多态
{
    p.show();
}

void test01(){
    Child c1(10,100);
    doWork(c1);
}

void test02()
{
    Child2<int> c2(10);
    doWork(c2);
}







int main()
{

    test01();
    test02();

    return 0;
}