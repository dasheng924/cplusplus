#include <iostream>

using namespace std;
class Base1
{
public:
    Base1()
    {
        m_A = 10;
    }


    int m_A ;

};

class Base2
{
public:
    Base2()
    {
        m_A = 20;
    }


    int m_A ;

};

class Son:public Base1,public  Base2
{
public:
    Son()
    {
        m_A = 30;
    }


    int m_A ;
};

void test01()
{
    Son s; //二义性问题，需要通过作用域来控制
    cout<<"Son m_A = "<<s.m_A<<endl;
    cout<<"Base1 m_A = "<<s.Base1::m_A<<endl; 
    cout<<"Base2 m_A = "<<s.Base2::m_A<<endl ;  

}

int main()
{
    test01();

    return 0;
}