#include <iostream>
#include <cstddef>
using namespace std;


#define offsetof(t, d) __builtin_offsetof(t, d)

class Base
{
public:
    virtual void func(){}
    int m_num;

};

class Derivel:public Base
{
public:

    int m_a;
};

class A
{

};

int main()
{

    cout<<sizeof(Base)<<endl;
    cout<<sizeof(Derivel)<<endl;
    cout<<sizeof(A)<<endl;
    
    cout<<offsetof(struct Base,m_num)<<endl;

    cout<<sizeof(int)<<endl;
    return 0;
}