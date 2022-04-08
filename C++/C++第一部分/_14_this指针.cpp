#include <iostream>
using namespace std;


/*
1.this 指针 ： 指向当前对象
2.可以解决命名冲突的问题
3.*this 代表本体
4.非静态成员函数才会有this指针

this指针是一种隐含指针，隐含于每一个类的非静态成员函数中，永远指向当前对象
作用：
    1，当形参的名字和类成员名字相同时，可以用this指针进行区分 this->value = value
    2. 在类的非静态成员函数中返回对象本身，可以return *this;

    



*/

class Age
{
public:
    Age(int age){this->age  = age ;}  //2.可以解决命名冲突的问题

    int getAge(void){return this->age ;} //1.this 指针 ： 指向当前对象
 
    

private:
    int age;

};

int main(void)
{
    Age a(100);
    cout<<"age = "<<a.getAge()<<endl; 
    


    return 0 ;
}