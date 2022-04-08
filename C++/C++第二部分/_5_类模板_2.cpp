#include <iostream>
#include <string>

using namespace std;


template <class NameType,class AgeType>
class Person{
public:
    Person(NameType name,AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    void show()
    {
        cout<<"name="<<this->m_name<<"\tage="<<this->m_age<<endl;
    }
    void adddAge(AgeType age)
    {
        this->m_age += age;
    }
private:
    NameType m_name;
    AgeType m_age;
};

//模板函数做函数参数

//1.具体化参数类型

void doWork1(Person<string,int> &p)
{
    p.show();
}

void test01()
{
    Person<string,int> p("alex",23);
    doWork1(p);
}



//2.模板化函数参数
template <typename T1,typename T2>
void doWork2(Person<T1,T2> &p)
{
    p.show();
}

void test02()
{
    Person<string,int> p("alex",23);
    doWork2(p);
}

//3.整个类进行模板化
template<class T>
void doWork3(T &p)
{
    p.show();
}

void test03()
{
    Person<string,int> p("alex",23);
    doWork3(p);
}





int main(void)
{

    Person<string,int>p1("alex",23);
    p1.show();
    p1.adddAge(10);
    p1.show();


    return 0; 
}