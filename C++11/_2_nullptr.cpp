#include <iostream>
using namespace std;

//初始化指针，防止空指针

/*
char *ptr = 0;
char *ptr = NULL;
*/
//NULL 和 0 在C++中是一样的；C语言NULL是 ((void*)0)

void func(char *p)
{
    cout << "void func(char *p)" << endl;
}

void func(int p)
{
    cout << "void func(int p)" << endl;
}

int main()
{
    func(nullptr);   // 想要调用重载函数 void func(char *p)
    func(250);    // 想要调用重载函数 void func(int p)

    return 0;
}

//out
/*
void func(char *p)
void func(int p)
*/


//nullptr 专用于初始化空类型指针，不同类型的指针变量都可以使用 nullptr 来初始化
//nullptr 无法隐式转换为整形，但是可以隐式匹配指针类型。在 C++11 标准下，相比 NULL 和 0，使用 nullptr 初始化空指针可以令我们编写的程序更加健壮。