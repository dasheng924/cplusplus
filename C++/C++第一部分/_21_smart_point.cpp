#include <iostream>
using namespace std;

//这个里面用到的重载 .  -> 运算符

class Person
{
public:
    Person(){} //要使用new 运算符分配内存，就需要写出默认的构造函数
    Person(int age):m_age(age){}
    void showAge(){cout<<"年龄"<<this->m_age<<endl ;}
    ~Person(){cout<<"Person 的析构！"<<endl;}

private:
    int m_age ;
};
//用来托管自定义类型的指针，让对象进行自动的释放

class SmartPoint
{
public:
    SmartPoint(Person * p) 
    {
        this->person = p;
    }

    Person * operator->()
    {
        return this->person ;
    }

    Person& operator*()
    {
        return *this->person;
    }
    ~SmartPoint(){ //智能指针析构的时候，就把原本的对象进行了析构
        if(this->person != nullptr)
        {
            delete this->person;
            this->person = nullptr;
        }
        cout<<"智能指针的析构"<<endl;
    }


private:
    Person * person; //1.把这个对象的指针作为私有成员
};

void test01()
{
    SmartPoint sp(new Person(100)) ;

    //重载->,以达到像指针一样的操作
    sp->showAge(); //原本的是 sp->->showAge() ,编译器进行了优化;sp-> 这个返回的是一个指针，所以需要sp->->这样才可以调函数

    (*sp).showAge();


}



int main(void)
{
    test01() ;

    


    return 0;
}