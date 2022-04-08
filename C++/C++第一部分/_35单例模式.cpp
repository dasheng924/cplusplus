// 饿汉式单例的实现:类和对象一起被创建出来，牺牲空间换时间
// 懒汉式的单例：对象在调用接口的时候创建，牺牲时间换空间

//可以在静态区 或者堆区创建
//可以用普通指针 或者智能指针



#include<iostream>
#include <memory>
using namespace std;

/*
//在类中，声明了一个 static singleClass obj;

class CSingleton //这个类中可以添加自己的数据
{
private:
    //构造 拷贝构造 赋值运算 析构 全部私有，为了防止在类外进行实例化
	CSingleton(){ cout << "单例对象创建！" << endl; };
	CSingleton(const CSingleton &);
	CSingleton& operator=(const CSingleton &);
	~CSingleton(){ cout << "单例对象销毁！" << endl; };
 
	static CSingleton myInstance; // 单例对象在这里！
    //为什么用static?
    //因为这个实例对象需要一直存在，直到程序结束，放在全局区里面
public:
    //提供一个接口，方便进行访问
	static CSingleton* getInstance()
	{		 
		return &myInstance; //返回的是那唯一一个对象的地址
	}
};
 
CSingleton CSingleton::myInstance ; //进行一个初始化

int main()
{
    CSingleton * p1 = CSingleton::getInstance();
    CSingleton * p2 = CSingleton::getInstance();
    CSingleton * p3 = CSingleton::getInstance();

    cout<<"p1 = "<<p1<<endl;
    cout<<"p2 = "<<p2<<endl;
    cout<<"p3 = "<<p3<<endl;

单例对象创建！
p1 = 0x10b05f0d0
p2 = 0x10b05f0d0
p3 = 0x10b05f0d0
单例对象销毁！
//这三个指针指向的是同一个


    return 0;
}

*/

//static singleClass * MyInstance ;
#if 0
//如果把这个单列对象变成一个指针 static singleClass * obj;
//这个接口也返回的是： static singleClass * getInstance();

class singleClass{

private:
    singleClass(){cout<<"单例模式对象创建"<<endl;}
    singleClass(const singleClass &obj);
    singleClass& operator=(const singleClass &obj);
    ~singleClass(){cout<<"单例模式对象销毁"<<endl;}

    static singleClass * myInstance ; // 这里相对上面的版本是改变了

public:
    static singleClass * getInstance()
    {
        return myInstance; // 这里相对上面的版本是改变了
    }

#if 0
    //1.手动进行释放
    static void releaseInstance()
    {
        delete myInstance;
    }
#endif

private:
    //2.定义一个内部类，这个内部类析构的时候，会顺带释放内存
    class SubClass{
    public:
        SubClass(){};//忘记写{} 导致一直编译不过，所以这些常规的东西应该标准的写出来
        ~SubClass(){
            if(nullptr != myInstance)
            {
                delete myInstance;
                myInstance = nullptr;
            }
        } 
    };
    //定义一个内部类对象，对象销毁，会自动释放MyInstance 
        static SubClass sub; //保持和MyInstance 一样的生命周期
};

singleClass* singleClass::myInstance = new singleClass();
//返回值  作用域::变量名
singleClass::SubClass singleClass::sub; //靠这个对象的析构带动MyInstance 的释放

 //!!!!!!
//?????
//这里分配了内存 却没有释放内存 
//myInstance 存储的是一个地址，实例存储在堆区
//？？？？？如何释放内存？？？？
//1。手动进行释放（怕忘记）
//2.定义一个内部类，进行指针的内存管理


int main()
{

    /*
 加括号调用没有参数的构造函数，不加括号调用默认构造函数或唯一的构造函数，看需求
 C++在new时的初始化的规律可能为：对于有构造函数的类，不论有没有括号，都用构造函数进行初始化；
 如果没有构造函数，则不加括号的new只分配内存空间，不进行内存的初始化，而加了括号的new会在分配内存的同时初始化为0。


    */
    singleClass * p1 = singleClass::getInstance();
    singleClass * p2 = singleClass::getInstance();
    singleClass * p3 = singleClass::getInstance();

    cout<<"p1 = "<<p1<<endl;
    cout<<"p2 = "<<p2<<endl;
    cout<<"p3 = "<<p3<<endl;

#if 0
    singleClass::releaseInstance(); //这样就可以达到目的
#endif
    /*
单例模式对象创建
p1 = 0x7f9267c05aa0
p2 = 0x7f9267c05aa0
p3 = 0x7f9267c05aa0
    */

    return 0;
}

#endif


//shared_ptr<singleClass> 
#if 0
class singleClass{
private:

    singleClass(){cout<<"单例模式对象创建"<<endl;}
    singleClass(const singleClass &obj);
    singleClass& operator=(const singleClass &obj);
    ~singleClass(){cout<<"单例模式对象销毁"<<endl;}
    //这个销毁的函数里面需要带参数 singleClass *
    static void destory(singleClass *){cout<<"在这里销毁MyInstance"<<endl;}

    static shared_ptr<singleClass> MyInstance;

public:
    static shared_ptr<singleClass> getInstance()
    {
        return MyInstance;
    }
};

shared_ptr<singleClass> singleClass::MyInstance(new singleClass(),singleClass::destory);


int main(void)
{

    shared_ptr<singleClass> p1 = singleClass::getInstance();
    // shared_ptr<singleClass> p2 = singleClass::getInstance();
    // shared_ptr<singleClass> p3 = singleClass::getInstance();
    


    // cout<<"p1 = "<<p1<<endl;
    // cout<<"p2 = "<<p2<<endl;
    // cout<<"p3 = "<<p3<<endl;
   
    

    return 0;
}

#endif

//懒汉式单例模式

#if 0
class singleClass{

private:
    singleClass(){cout<<"单例对象被创建"<<endl;}
    singleClass(const singleClass & obj){}
    singleClass &operator=(const singleClass &obj);
    ~singleClass(){cout<<"单例对象被销毁"<<endl;}
public:
    static singleClass * getInstance()
    {
        lock();
        static singleClass MyInstance;
        unlock();
        return &MyInstance;
    }
};
#endif



class CSingleton
{
private:
	CSingleton(){ cout << "单例对象创建！" << endl; };
	CSingleton(const CSingleton &);
	CSingleton& operator=(const CSingleton &);
	~CSingleton(){ cout << "单例对象销毁！" << endl; };
 
	static CSingleton *myInstance;
 
 
public:
	static CSingleton * getInstance()
	{	
		if (nullptr == myInstance)
		{
            //lock();
            //再次的判断为了防止多个线程取得锁，导致对象创建多个
            if(nullptr == myInstance)
            {
                myInstance = new CSingleton();
            }
            //unlock();
			
		}
		return myInstance;
	}
 
private:
	// 定义一个内部类
	class CGarbo{
	public:
		CGarbo(){};
		~CGarbo()
		{
			if (nullptr != myInstance)
			{
				delete myInstance;
				myInstance = nullptr;
			}
		}
	};
	// 定义一个内部类的静态对象
	// 当该对象销毁时，顺带就释放myInstance指向的堆区资源
	static CGarbo m_garbo;
};

CSingleton * CSingleton::myInstance = nullptr;
CSingleton::CGarbo CSingleton::m_garbo;


int main(void)
{
    CSingleton *p1 = CSingleton::getInstance();
    CSingleton *p2 = CSingleton::getInstance();
    CSingleton *p3 = CSingleton::getInstance();

    cout<<"p1 = "<<p1<<endl;
    cout<<"p2 = "<<p2<<endl;
    cout<<"p3 = "<<p3<<endl;


    
    return 0;
}



//-------------
//静态变量的方式，饿汉和懒汉

#if 0
class singleClass{
private:
    singleClass(){cout<<"单例对象创建完成"<<endl;}
    singleClass(const singleClass &obj);
    singleClass& operator=(const singleClass &obj);
    ~singleClass(){cout<<"析构"<<endl;}


    //饿汉:类和对象一起被创建
    static singleClass myInstance;

public:
    static singleClass* getInstance()
    {
        return &myInstance;
    }

#endif





#if 0

class singleClass{
private:
    singleClass(){cout<<"单例对象创建完成"<<endl;}
    singleClass(const singleClass &obj);
    singleClass& operator=(const singleClass &obj);
    ~singleClass(){cout<<"析构"<<endl;}



    //懒汉：调用接口时才创建对象，多线程中存在同步问题

public:
    static singleClass *getInstance()
    {
        static singleClass myInstance;
        return &myInstance;
    }

};

#endif


//饿汉
//1.最简单的static变量，返回地址
//2.改成static 指针，在类外进行初始化。返回这个指针，自己加一个函数，用于手动释放内存
//3.把2 中的手动释放内存改成 内部类的析构函数进行自动释放，前提：在原类中加一个静态的内部类对象
//4.shared_ptr<>智能指针进行管理，原有的类指针的地方，全部换成智能指针，指针指针，在初始化的时候要加上一个删除器


//懒汉
//1.最简单的static对象，直接在接口中进行创建
//2.类指针的初始化在接口中，同时需要一个内部类进行内存的自动销毁

//懒汉模式在多线程的情况下，需要加锁
