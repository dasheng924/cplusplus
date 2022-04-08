//深拷贝

//两个对象直接可以进行赋值，c++提供了简单的拷贝功能，逐个字节的拷贝
//当类中有指针，并且动态分配内存的时候，就会有问题
//浅拷贝：两个对象中的指针，指向的是同一块堆内存，这个内存在析构函数释放的时候会释放两次，等都
//第二次释放的时候，释放的是一块不存在的内存，就会异常

//怎么解决这个问题？？？？
//深拷贝：自己在构造函数和拷贝构造和赋值运算符中，重写赋值的操作，
//分配一块新的内存，用于拷贝，这样析构函数，释放的时候就是释放的各自的内存区域





#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    int m_age;
    char * m_pNmae;
public:
    Person(int age,char * pName);
    Person(const Person &p);
    inline void show(){cout<<"name:"<<m_pNmae<<"\tage:"<<m_age<<endl ;}
    ~Person();
};


Person::Person(int age,char * pName)
{
    m_pNmae = (char *)malloc(strlen(pName) + 1) ;
    strcpy(m_pNmae,pName);
    m_age = age;
}

Person::Person(const Person &p)
{
    m_pNmae = (char *)malloc(strlen(p.m_pNmae) + 1);
    strcpy(m_pNmae,p.m_pNmae);
    m_age  = p.m_age;
}


Person::~Person()
{
    if(m_pNmae != NULL)
    {
        free(m_pNmae);
        m_pNmae = NULL;
    }
}



int main(void)
{
    Person p(12,(char*)"alex") ;
    p.show();
    


    return 0;
}