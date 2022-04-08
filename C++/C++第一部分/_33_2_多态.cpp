#include <iostream>

using namespace std;

class A
{
public:
    virtual void func(){
        cout<<"A func()"<<endl;
    }

    void exec(){
        func();
        cout<<"A exec()"<<endl;
    }

};

class B:public A
{
public:
    virtual void func()
    {
        cout<<"B func()"<<endl;
    }
};

B *g_b = 0;

int main()
{

    B b;
    g_b = &b;
    g_b->exec();

    b.exec();

    A *ptr = &b;
    ptr->exec();

    return 0;
}

/*
B func()
A exec()
B func()
A exec()
原本认为是 A func()  A exec()
分析原因: 子类重写了父类的func(),导致指针指向的时候,调用的还是子类的func()


内存布局B:
__vfptr--->原来是A::func() ,现在重写了,就变成了B::func()

不管是A类的指针,还是B类的指针,都会去调用B::func()

--->这个也就是虚函数的覆盖问题



*/