#include <iostream>
#include <stdexcept>
#include <string>

//自己异常类的封装

using namespace std;

class myOutORangeException:public exception
{
public:
    myOutORangeException(string errorInfo)
    {
        this->m_errorInfo = errorInfo ;
    }
    virtual const char* what() const _NOEXCEPT
    {
        return this->m_errorInfo.c_str();
    }

    virtual ~myOutORangeException(){}

    string m_errorInfo;

};

class Person
{
public:
    Person(int age)
    {
        this->m_age = age ;
        if(this->m_age < 0 || this->m_age > 200)
        {
            //throw out_of_range("年龄越界!") ;
            throw myOutORangeException("长度越界!") ;
        }
    }

    int m_age;
};

void test01()
{

    try{
        Person p(300);
    }
    catch(myOutORangeException &e)
    {
        cout<<e.what()<<endl ;
    }


}

int main()
{

    test01();

    return 0;
}