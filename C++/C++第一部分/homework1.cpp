/*
1.设计一个类，求圆的周长。
2.设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

const double PI = 3.1415;
class Circle
{
private:
    double m_r;
public:
    Circle(double r):m_r(r){}
    double GetR(){return m_r ;}
    double GetC(){return 2*PI*m_r ;}
    double GetS(){return PI*m_r*m_r ;}

};


class Student{
private:
    string m_name;
    int m_age;

public:
    Student(string name,int age):m_name(name),m_age(age){}
    string GetName(){return m_name;}
    int GetAge(){return m_age;}
    void putName(string name){m_name = name;}
    void putAge(int age){m_age = age;}
};

void test01()
{

    Circle c1(2.32);
    cout<<"r = "<<c1.GetR()<<"\tC = "<<c1.GetC()<<"\tS = "<<c1.GetS()<<endl;
}

void test02()
{
    Student s1("alex",23);
    cout<<"name:"<<s1.GetName()<<"\tAge:"<<s1.GetAge()<<endl;

    s1.putName("lucy");
    s1.putAge(99);
    cout<<"name:"<<s1.GetName()<<"\tAge:"<<s1.GetAge()<<endl;

}

int main(void)
{
    //test01();
    test02();

    return 0 ;
}

