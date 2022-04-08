#include <iostream>
#include <thread>

using namespace std;

#if 0
void myprint(const int &i,char * buf) //子线程不要传入指针
{
    cout<<i<<endl; //当用了detach后发现 i 不是取的引用，而是直接把值进行了拷贝，已经传入了子线程里面（和前面的局部变量做类的构造参数不一样）
    cout<<buf<<endl; //当用了detach之后，这个buf的数据无法传入，导致buf无效

    return;
}
#else
void myprint(const int i,const string &buf)//i 直接用传值的方式   buf 从原来的char * -->string 会自动隐式类型转换，转换后已经不是原来的char*
{
    cout<<i<<endl;
    cout<<buf.c_str()<<endl; //string这个问题会存在：存在main函数执行完了，系统用buf转为为string类型的可能性，也是存在不安全的

    __thread_id tid = this_thread::get_id();
    cout<<"子线程的ID = "<<tid<<endl;
    return;
}



#endif

int main() {
    //传递临时对象作为线程参数

    int num = 10;
    int &num1 = num;
    char buf[] = "this is a test";

    thread myjob(myprint,num,string(buf)); //事实上，存在main函数执行完了，系统用buf转为为string类型的可能性，也是存在不安全的
    //string(buf) -->生成一个临时的string对象（匿名对象），就会绑定到函数的形参上面，这样就不会存在上面的问题
    //会先调用构造函数生成一个匿名对象，再调用thread的构造函数，这里面会发生一个拷贝构造传参给buf,而myprint的const & buf这里面的引用，是不起作用的

    //事实1：只要使用临时构造的对象传入给线程的 构造函数，可以确保detach后，

    myjob.join(); //当使用join时不会发生问题，因为局部变量不会销毁
    //myjob.detach() ;

    //总结：1。传递简单的类似于int类型，建议都是值传递
    //2。如果要传入类对象，避免隐式类型转换，全部都在thread的构造函数里构造出来临时对象 ，classname(构造函数参数)
    //在函数参数里面用引用来接，否则会多调用一次拷贝构造，

    //终极结论：建议不使用detach，直接使用join，不存在局部变量失效导致的对非法内存的访问

    //std::this_thread::get_id()
    __thread_id tid;
    tid = this_thread::get_id();
    cout<<"主线程的ID = "<<tid<<endl;
    return 0;
}
