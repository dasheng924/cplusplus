#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    int m_age;
    string m_name;
};

template<typename T>
bool myCompar(T &a,T &b)
{
    if(a == b) 
        return true;
    return false;
}

//具体自定义类型，解决上述问题,
//template<> 返回值 函数名<类型> 参数列表（具体划类型）
template<> bool myCompar<Person>(Person &a,Person &b)
{
    if(a.m_age == b.m_age )
        return true;
    return false;
}





void test01()
{
    Person p1("alex",23);
    Person p2("Lucy",22);

    if(myCompar(p1,p2))
        cout<<"相等"<<endl ;
    else
        cout<<"不相等"<<endl;



}

int main()
{
    test01();


    return 0;
}