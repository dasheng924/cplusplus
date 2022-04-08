#include <iostream>

using namespace std;

class B;
class A
{
public:
    weak_ptr<B> pb_;//用weak_ptr保存shared_ptr 这样引用计数不会增加
    ~A(){cout<<"A desc"<<endl;}
};

class B
{
public:
    shared_ptr<A> pa_; //用shared_ptr 保存了shared_ptr,导致引用计数增加了.
    ~B(){
        cout<<"B desc"<<endl;
    }

};


//循环引用的问题:用weak_ptr 就不会造成环的效果
void func()
{
    shared_ptr<A> pa(new A);
    shared_ptr<B> pb(new B);

    cout<<"pa count="<<pa.use_count()<<endl;//1
    cout<<"pb count="<<pb.use_count()<<endl;//1

    pa->pb_ = pb;
    pb->pa_ = pa;

    cout<<"pa count="<<pa.use_count()<<endl;//2
    cout<<"pb count="<<pb.use_count()<<endl;//2
}

//-------------
//返回管理了this指针的shared_ptr,会出现析构两次的情况

class Test
{
public:
    shared_ptr<Test> getSharedPtr()
    {
        return shared_ptr<Test>(this);
    }
    ~Test()
    {
        cout<<"Test desc"<<endl;
    }

};

void func1()
{   
    //使用了同一个this指针构造出了两个智能指针
    shared_ptr<Test> ptr1(new Test);
    cout<<"use_count="<<ptr1.use_count()<<endl;
    shared_ptr<Test> ptr2 = ptr1->getSharedPtr();
    cout<<"use_count="<<ptr1.use_count()<<endl;
    



}




int main()
{
    // func();

    func1();

    exit(0);
}