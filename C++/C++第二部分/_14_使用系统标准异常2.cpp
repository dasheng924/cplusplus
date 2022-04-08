#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class MyOutOfangeException:public exception
{
public:
    MyOutOfangeException(string info)
    {
        this->ErrMsg = info;
    }
    
    virtual const char *what()const{
        cout<<this->ErrMsg<<endl;
    }
    virtual ~MyOutOfangeException(){}
private:
    string ErrMsg;

};

class Person{
public:
    Person(int age)
    {
        this->age =age;
        if(this->age < 0 || this->age > 200)
        {
            throw MyOutOfangeException("年龄范围错误！");
        }
       
    }

    int age;
};

void test01(){

    try{
        Person p(300);
    }
    catch(exception &e)
    {
        e.what();
    }
    catch(...)
    {
        cout<<"..."<<endl;
    }

}

int main(void)
{   
    test01();

    return 0;
}