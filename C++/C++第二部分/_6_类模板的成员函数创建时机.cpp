#include <iostream>
#include <string>


using namespace std;

class Person1
{
public:
    void showPerson1(){cout<<"Person1 的调用！"<<endl;}

};

class Person2
{
public:
    void showPerson2(){cout<<"Person2 的调用！"<<endl;}
};

template <class T>
class myClass
{
public:
    T obj;

    void func1()
    {
        obj.showPerson1();
    }

    void func2()
    {
        obj.showPerson2();
    }
};

void test01()
{
    myClass<Person1> obj;
    obj.func1() ; //类模板 成员函数不会一开始就创建出来，而是在运行是才会创建出来
    //因为要是提前创建出来，可以根据obj 的类型就可以确定出来调用的 showPerson 的方法是否匹配

    //obj.func2();  

}

int main()
{

    test01();
    return 0;
}
