#include <iostream>

using namespace std;

class myException
{
public:
    void printErr()
    {
        cout<<"Err"<<endl ;
    }
};

class Person
{
public:
    Person(){cout<<"Person cons"<<endl ;}
    ~Person(){cout<<"Person desc"<<endl ;}
};


int Devied(int a,int b)
{
    if(b == 0)
    {

        Person p; //栈解旋：从try开始到抛出异常之前，栈上所有的内存开辟会被回收
        throw myException(); //抛出一个匿名对象
        //throw -1 ;
    }
    return a/b ;
}


void test01()
{
    int a = 10;
    int b = 0;
    try{ //发生异常的程序放到里面
        Devied(a,b);
    }
    
    catch(int)//异常机制是严格类型匹配的
    {
        throw; //不行处理，继续抛出异常;如果不处理，程序中断    
        cout<<"int 类型异常捕获"<<endl ;
        
    }
    catch(double)
    {
        cout<<"double 类型异常捕获"<<endl ;
    }
    catch(myException &e)
    {
        e.printErr();
    }
    catch(...)
    {
         cout<<"其他类型异常捕获"<<endl ;
    }

}

int main()
{
    try
    {
         test01();
    }
    catch(int)
    {
        cout<<"main 函数中捕获int异常"<<endl;
    }
    catch(...)
    {
        cout<<"main 函数中捕获其他异常"<<endl ;
    }
    

    return 0;
}

