#include <__bit_reference>

#pragma once
#include <iostream>
#include <string>

using namespace std;

//1.最开头的类声明和友元函数声明
template<class T1,class T2>
class Person;

template<class T1,class T2>
void show2(Person<T1,T2> &person);

template<class T1,class T2>
class Person
{
public:
    Person(T1 age,T2 name);
    //友元函数类内实现，就没有什么特殊的要求
    friend void show1(Person<T1,T2> &person)
    {
        cout<<"name:"<<person.m_name<<"\tage:"<<person.m_age<<endl;
    }

    //2.类中的友元函数声明，记住函数名<>
    __unused friend void show2<>(Person<T1,T2> &person);  //show2<> 1.先声明这是一个模板函数，显式的写<>

private:
    T1 m_age;
    T2 m_name;
};



template<class T1, class T2>
Person<T1, T2>::Person(T1 age, T2 name) {
    this->m_age = age;
    this->m_name = name;
}


//在类外实现这个模板函数
//3.类外的实现，不需要函数名后面加<>
template<class T1,class T2>
void show2(Person<T1, T2> &person) {
    cout<<"name:"<<person.m_name<<"\tage:"<<person.m_age<<endl;
}








