#include <iostream>
#include <memory>
using namespace std;

class Person{

public:
    Person(){}
    Person(int age){this->m_age = age;}
    inline void showMsg(){cout<<"age="<<m_age<<endl;}
    ~Person(){cout<<"desc"<<endl;}

private:
    int m_age;
};

class SmartPoint{
public:
    SmartPoint(Person *p){
        this->p = p;
    }


    ~SmartPoint(){
        if(p != nullptr)
        {
            delete p;
            p = nullptr;
        }
        cout<<"SmartPoint desc"<<endl;
    }

//重载这两个的意思是方便把这个智能指针对象当作指针来用
    Person* operator->()
    {
        return this->p;
    }
    Person& operator*()
    {
        return *this->p;
    }

private:
    Person *p; //要维护的是要保护的对象指针

};



int main(void)
{   
    SmartPoint ptr(new Person(100));//创造一个智能指针对象

    ptr->showMsg(); //本质上是ptr->->showMsg()
    (*ptr).showMsg();

    //shared_ptr<Person> ptr(new Person[10],default_delete<Test[]>());

    


    return 0;
}