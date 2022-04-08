#include <iostream>
#include <string>

using namespace std;


//类内实现就直接在类内实现就好，和普通的成员函数是没有区别的

template<class T1,class T2>
class Person
{
public:
/*
//类内实现
    Person(T1 age,T2 name)
    {
        this->m_age = age;
        this->m_name = name;
    }
*/
    Person(T1 age,T2 name);


    //类内实现
    void show() const
    {
        cout<<this->m_name<<"\t"<<this->m_age<<endl ;
    }
    void show2();
   

    T1 m_age;
    T2 m_name;
};

//类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 age,T2 name)
{
    this->m_age = age;
    this->m_name = name;
}


template <class T1,class T2>
void Person<T1,T2>::show2() //作用域也要带模板参数
{
   cout<<m_name<<m_age<<endl;
   //cout<<Person<T1,T2>::m_name<<"\t"<<Person<T1,T2>::m_age<<endl;

}

void test01()
{
    Person<int,string> p(12,"gogo");
    p.show2();
}

int main()
{
    test01();

    return 0;
}