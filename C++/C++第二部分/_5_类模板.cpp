#include <iostream>
#include <string>

using namespace std;

//template <class NameType,class AgeType>
//2.可以有默认类型参数
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

void test01()
{

    Person<string,int> p1("alex",23);  //1.类模板不支持隐式类型转换，必须要显式指定类型
    p1.show();


}

int main()
{

    test01();
    return 0;
}