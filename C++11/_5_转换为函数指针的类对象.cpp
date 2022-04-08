#include <iostream>
#include <string>
using namespace std;


using func_ptr = void(*)(int,string);

class Test
{
public:
    static void print(int a,string b)
    {
        cout<<"a="<<a<<"\tb="<<b<<endl;
    }

    //将类对象转为函数指针
    operator func_ptr()
    {
        return print;
    }
};

int main()
{
    Test t;
    t(11,"apple");
    return 0;
}