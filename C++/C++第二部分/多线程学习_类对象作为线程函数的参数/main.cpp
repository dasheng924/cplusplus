#include <iostream>
#include <thread>

using namespace std;

class  A
{
public:
    A(int i ):m_i(i)
    {
        cout<<"我是A的构造函数，我的线程ID是"<<this_thread::get_id()<<endl;
    }
    A(const A& a)
    {
        m_i = a.m_i;
        cout<<"我是A的拷贝构造函数，我的线程ID是"<<this_thread::get_id()<<endl;
    }
    void thread_work(int num)
    {
        cout<<"子线程执行了thread_work，我的线程ID是"<<this_thread::get_id()<<endl;
    }
    void operator()(int num)
    {
        cout<<"子线程执行了operator()，我的线程ID是"<<this_thread::get_id()<<endl;
    }


    int m_i; //mutable -->对应传入的是类对象或者匿名对象
};

//void myprint(const A &obj) //这里传的时候用的已经是A对象的拷贝，不是原对象 -->对应传入的是类对象或者匿名对象
//void myprint(A &obj) //---》对应std::ref(obj),这样就不会调用拷贝构造了，可以进一步节省资源，提高执行效率
//传入智能指针
void myprint(unique_ptr<int>ptr) //独占式的智能指针
{
   cout<<"子线程的myprint的地址是"<<&myprint<<"\t线程ID是"<<this_thread::get_id()<<endl;
   //obj.m_i = 999; //这样的修改是不能改变主线程中传参对象的值 -->对应传入的是类对象或者匿名对象

}


int main() {

//1。 临时对象的传参方式
//    int num = 10 ;
//    thread myjob(myprint,A(10)); //A(obj) 临时对象的传参方式，可以保证用detach的时候是安全的


    //2。以类对象作为线程的参数
    //A obj(10);
   // thread myjob(myprint,obj);//--->  改为thread myjob(myprint,std::ref(obj));



   //3。td::ref(obj) //这样做传入的是真正的本身，不会传入的是一份拷贝
//   A obj(100);
//   thread myjob(myprint,std::ref(obj)); //这样做传入的是真正的本身，不会传入的是一份拷贝，必须用join
   //void myprint(A &obj);


   //4。
//   unique_ptr<int> p(new int(100));
//   thread myjob(myprint,std::move(p));
//    //独占式指针只能通过std::move()才可以传递给另一个指针
//    //传递后up就指向空，新的ptn指向原来的内存
//    //所以这时就不能用detach了，因为如果主线程先执行完，ptn指向的对象就被释放了


    //5类的成员函数作为线程的执行函数
//    A obj(100);
//    thread myjob(&A::thread_work,obj,15);//&A::thread_work成员函数地址,obj对象名称,15成员函数参数 .这种情况也可以用detach

    //6。operator()
    A obj(100);
    thread myjob(obj,10); //operator()



//总结：
    //1。优先join
    //2。匿名函数-->join and detach ok 和std::ref(obj)--->必须join



    myjob.join() ;
    //myjob.detach();

    cout<<"我是主线程，我的ID是"<<this_thread::get_id()<<endl;

    return 0;
}
