#include <iostream>
#include <cstring>

using namespace std;

class Person
{
public:
    Person(char *name,int age)
    {
        m_pName = new char[strlen(name) + 1] ;
        strcpy(m_pName,name) ;
        this->age = age;
    }
  

    Person& operator=(const Person &obj)
    {
        //1.原先的内容进行释放
        if(this->m_pName != nullptr)
        {
            delete []this->m_pName;
            this->m_pName = nullptr;
        }

        //2.给新的内容进行拷贝赋值
        this->m_pName = new char[strlen(obj.m_pName) +1] ;
        strcpy(this->m_pName,obj.m_pName);
        this->age = obj.age ;

        //3.返回这个对象
        return *this;
    }
    

    void show()const {cout<<"name = "<<this->m_pName<<"\tage = "<<this->age<<endl; }
    ~Person()
    {
        if(m_pName != nullptr)
        {
            delete []this->m_pName;
            this->m_pName = nullptr ;
        }
    }

private:
    char *m_pName;
    int age;
};

void test01()
{
    Person p1((char *)"alex",23);
    Person p2((char *)"lucy",22);
    p1=p2;
    p1.show();
}

int main(void)
{
    test01() ;

    return 0 ;
}