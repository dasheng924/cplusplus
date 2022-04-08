#include <iostream>

using namespace std;

class myException
{
public:
    myException(){cout<<"cons"<<endl ;}
    myException(const myException & obj)
    {
        cout<<"cpoy cons"<<endl ;
    }
    ~myException(){cout<<"desc"<<endl ;}
    void printErr()
    {
        cout<<"Err"<<endl ;
    }
};


void doWork()
{
    throw new myException();
}
void test01()
{
    try
    {
        doWork();
    }
    catch(myException *e)
    {
        e->printErr();
        cout<<"捕获异常"<<endl ;

        delete e; //堆上，需要自己去释放内存
    }
}


/*
1.catch(myException e)
cons  --这个默认构造不会立即析构，会存活到catch结束
cpoy cons  
Err
捕获异常
desc
desc

2.catch(myException &e)
cons --》 myException &e 这个e还是默认构造出来的那个，节省了开销
Err
捕获异常
desc

3.catch(myException *e)
cons  --需要自己析构掉
Err
捕获异常

*/

int main()
{   
    //test01();
/*
    myException * ptr = nullptr;
    ptr->printErr(); //空指针， 也可以指向成员函数，这个成员函数中不涉及this指针
*/
    return 0;
}
