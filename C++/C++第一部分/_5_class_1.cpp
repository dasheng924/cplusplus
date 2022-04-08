/*
1.构造函数和析构函数


*/

#include <iostream>
#include <cstring>

using namespace std;

class Person
{

public:
    Person();
    ~Person();

public:
    char *m_pNmae;
    int m_age;

};

Person::Person()
{
    cout<<"Welcome 构造函数"<<endl;
    ssize_t len = sizeof("alex") ;
    cout<<len<<endl ;
    m_pNmae = (char*)malloc(sizeof("alex")) ;
    strcpy(m_pNmae,"alex");
    m_age = 100;
}

Person::~Person()
{
    cout<<"析构函数！"<<endl; 
    if(m_pNmae != nullptr)
    {
        free(m_pNmae);
        m_pNmae  = nullptr ;
    }

    if(m_pNmae == nullptr)
        cout<<"内存释放完成!"<<endl; 
}

int main(void)
{
    Person p;
    cout<<"name :"<<p.m_pNmae<<"\tage:"<<p.m_age<<endl ;

    return 0;
}