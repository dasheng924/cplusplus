#include <iostream>

using namespace std;

class Test
{
public:
    Test(int num):m_param(num){}

    void show() const{
        cout<<"okok!"<<endl;
        cout<<"m_param="<<m_param<<endl;
    }

    int m_param;
};

using ptrType = void(Test::*)()const;

int main()
{

    ptrType p = &Test::show; 

    Test t(111);
    (t.*p)();
    Test *t2 = &t;
    (t2->*p)();
//（<类对象名>.*<非静态成员函数>）（<参数列表>）
   //（<类对象指针>->*<非静态成员函数>）（<参数列表>）


    return 0;
}
