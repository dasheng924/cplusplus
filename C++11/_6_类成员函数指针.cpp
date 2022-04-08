#include <iostream>
#include <string>
using namespace std;


class Test
{
public:
    void print(int a,string b)
    {
        cout<<"a="<<a<<"\tb="<<b<<endl;
    }
    int m_num;
};

int  main()
{
    //类成员函数指针指向类成员函数
    void (Test::*fun_ptr)(int,string) = &Test::print;
    // 类成员指针指向类成员变量
    int Test::*num_ptr = &Test::m_num;

    Test t;

    // 通过类成员函数指针调用类成员函数
    (t.*fun_ptr)(11,"apple");
    // 通过类成员指针初始化类成员变量
    (t.*num_ptr) = 111;
    cout<<t.m_num<<endl;
    
    return 0;
}