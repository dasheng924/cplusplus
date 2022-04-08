#include <iostream>

using namespace std;

class Test
{
public:
    Test(int num):m_param(num){}

    int m_param;
};


int main()
{

    //定义一个指向成员变量的指针
    int Test::*ptr = &Test::m_param;

    //解引用
    //类成员解引用
    Test t(10);
    cout<<t.*ptr<<endl;//10
    //类指针解引用
    Test *t2 = &t;
    cout<<t2->*ptr<<endl;//10








    return 0;
}