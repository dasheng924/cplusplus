#include <iostream>

using namespace std;

class Complex
{
public:
    void operator()() //重载()运算符，达到对象直接调用 
    {
        cout<<"hello world"<<endl ;
    }


};

void test()
{
    Complex c;
    c(); //仿函数，和函数调用的方式是相同的，但是不是个函数

    Complex()(); //Complex() 是一个匿名对象
}

int main(void)
{
    test();

    return 0;
}


