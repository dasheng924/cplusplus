#include <iostream>
using namespace std;

class BaseException
{
public:
    virtual void printErr(){};
};


class NullPointException:public BaseException
{
public:
    virtual void printErr()
    {
        cout<<"空指针异常"<<endl ;
    }
};

class YueJieException:public BaseException
{   
    virtual void printErr()
    {
        cout<<"越界异常"<<endl ;
    }
};

void doWork()
{
    throw NullPointException(); 
}

void test()
{
    try{
        doWork() ;
    }
    catch(BaseException &e) //这个地方发生多态，根据接受对象类型的不同，调用不同的函数
    {
        e.printErr();
    }
}




int main()
{
    test();

    return 0;
}