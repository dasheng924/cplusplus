#include <iostream>
#include <string>

using namespace std;



template <class NameType,class AgeType=int>
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        this->m_age = age;
        this->m_name = name;
    }
    void show(){cout<<m_name<<"\t"<<m_age<<endl ;}

    NameType m_name;
    AgeType m_age;
};

//1.指定具体参数类型
void doWork(Person<string,int> &p)
{
    p.show();
}

void test01()
{
    Person<string,int> p("alex",23);
    doWork(p);
}


//2.参数模板化,和函数模板配合使用

template<typename T1,typename T2>
void doWork2(Person<T1,T2> &p)
{
    p.show();
    cout<<typeid(T1).name()<<endl ;
   // cout<<typeid(T2).name()<<endl ;
}

void test02()
{
    Person<string,int> p("Lucy",33);
    doWork2(p);
}

//3.整体模板化
template<class T>
void doWork3(T &p)
{
    p.show();
    //cout<<typeid(T).name()<<endl ;
}

void test03()
{
    Person<string,int> p("Lucy",33);
    doWork3(p);
}



int main()
{
    test01();
    test02();
    test03();
    return 0;
}