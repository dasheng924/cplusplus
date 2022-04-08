#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>

using namespace std;


//线程的入口函数
void myPrint(int num)
{
    cout<<"子线程开始执行,ID = "<<num<<endl;

    cout<<"子线程结束执行,ID = "<<num<<endl ;
}

class A{
public:
    void inMsgList()
    {
        for(int i = 0;i<1000;++i)
        {
            //存入玩家的指令
            std::lock_guard<mutex> sbguard(mymutex);
            //std::unique_lock<mutex> myunique(mymutex,std::defer_lock ) ;

            //lock_guard构造函数执行了mutex::lock();在作用域结束时，调用析构函数，执行mutex::unlock()
            //可以加{} 作用域按要求结束 lock_guard
//            mymutex.lock();
            MsgList.push_back(i);
            cout<<"in---->"<<i<<endl;
//            mymutex.unlock();
        }
    }
    void outMsgList()
    {
        for(int i = 0;i<1000;++i)
        {
            mymutex.lock();
            if(!MsgList.empty())
            {
                //读取玩家指令
                int num = MsgList.front();
                cout<<"out---->"<<num<<endl;
                MsgList.pop_front();
            }
            mymutex.unlock();
        }

    }
private:
    list<int> MsgList;
    std::mutex mymutex;
};

int main() {

/*
    vector<thread> moreThread;
    for(int i = 0;i<10;++i)
    {
        moreThread.push_back(thread(myPrint,i)); //创建10个线程，并且开始执行子线程；这个输出是没有顺序的
    }

    for(auto it = moreThread.begin();it!=moreThread.end();++it)
        it->join();

    cout<<"主线程运行结束"<<endl;
*/


    //互斥量：mutex---------------------------------------------------------------
    //lock 来进行尝试加锁，只有一个线程可以加锁成功，如果有返回就是锁成功了；如果锁不成功就阻塞在哪里
    //unlock
    //lock和unlock的临界区域要保证粒度要小，加锁区域要合理;lock 和unlock 要配合使用，不能忘记unlock

    //忘记unlock的解决办法----------------------------------------------------------
    //lock_guard构造函数执行了mutex::lock();在作用域结束时，调用析构函数，执行mutex::unlock()
    //可以加{} 作用域按要求结束 lock_guard
    //std::lock_guard<mutex> sbguard(mymudex) ; 来替代成对的 lock unlock
    //std::lock_guard<mutex>  lock_guard对象名称 (互斥量对象)

    //死锁的一般解决方案：
    //只要保证多个互斥量上锁的顺序一样就不会造成死锁。

    //-------------------------------------------------》多个互斥量调用的时候
    //涉及到多个互斥量的时候才可以用std::lock()
    //std::lock(互斥量1，互斥量2，互斥量3) 不会存在锁的时候考虑互锁的情况，也就是多个锁要按照顺序来执行
    //如果互斥量中一个没锁住，它就等着，等所有互斥量都锁住，才能继续执行。
    //如果有一个没锁住，就会把已经锁住的释放掉（要么互斥量都锁住，要么都没锁住，防止死锁）



//    std::lock(mymutex1,mymutex2); //可以一次性调用多个互斥量，而不需要在意调用顺序的问题
//    std::lock_guard<mutex> sbguard(mymutex1,std::adopt_lock_t) ; //
//    std::lock_guard<mutex> sbguard(mymutex2,std::adopt_lock_t) ;//参数二就是为了说明上面已经调用了std::lock了
//    就不调用lock_guard 构造时的lock 了

//    std::adopt_lock  结构体对象，标记已经lock过了，不需要在lock了




//    unique_lock<mutex> obj_name(mymutex) ; 缺省参数这样的使用和lock_guard 是没有什么区别的
 //   参数二：
 //     std::adopt_lock_t  这个表示已经lock了，不需要再进行lock了，通知unique_lock 的构造函数中不需要再lock，前提：必须提前lock
 //     std::try_to_lock 表示尝试去加锁，加锁不成功，不会进行阻塞,可以去去干点别的事情；前提是：不要提前进行lock操作
        //owns_lock() 可以检测是否拿到锁了
        //std::chrono::milliseconds duar(20000) ; //20s 延时20s
//        std::chrono::microseconds duar(20) ;
//        std::this_thread::sleep_for(duar) ; ------>睡眠一定的时间

//        std::defer_lock(); 表示没有给mutex加锁，也就是初始化了一个没有加锁的mutex；前提是不能先lock，否则会报异常
        //介绍一些 unique_lock 的成员函数
        // 1。lock() ; //不用关心去unlock    // std::unique_lock<mutex> myunique(mymutex,std::defer_lock);
        //2。unlock（） 当你想去在unique_lock之后的代码片段中操作一些非共享数据，就可以提前进行unlock，完了之后再lock（）
        /*
         * std::unique_lock<mutex> myunique(mymutex,std::defer_lock) ;
         *
         * unlock（）；
         * .....非共享片段
         *
         * lock()
         * 共享片段
         *
         */
        //3。try_lock() 和上面的try_to_lock 是一样的-
        //4。release：返回它管理的mutex对象的指针，并释放所有权，也就是myunique 和mymutex不再有关联；如果原来的mutex处于加锁状态，要自己接管，然后解锁
//        std::unique_lock<mutex> myunique(mymutex);
//        std::mutex *ptr = myunique.release() ;
//        ptr->unlock();//你需要自己unlock





        //-------------------------
    //创建取指令和存指令的线程
    A obj;
    thread inThread(&A::inMsgList,std::ref(obj));
    thread outThread(&A::outMsgList,std::ref(obj));

    inThread.join();
    outThread.join();

    return 0;
}
