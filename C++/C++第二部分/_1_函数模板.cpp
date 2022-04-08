#include <iostream>

using namespace std;

//template<class T>  typename 和 class 是一样的
template<typename T>
void change(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

void test()
{   
    int a = 10;
    int b = 20;

    //1.隐式类型推导
    //change(a,b);
    //显式指定类型
    change<int>(a,b);

    cout<<"a = "<<a<<"\tb = "<<b<<endl ;
}
int main()
{
    test();

    return 0;
}

//1.把数据类型参数化，表达逻辑结构相同
//2.分为函数模板和类模板

