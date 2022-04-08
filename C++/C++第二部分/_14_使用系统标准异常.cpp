#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class myOutORangeException:public exception//1.继承 exception
{
public:
    myOutORangeException(string errorInfo)
    {
        this->m_errorInfo = errorInfo ;
    }
    virtual const char* what() const //2.重写 what()
    {
        return this->m_errorInfo.c_str();
    }

    

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