#include <iostream>

using namespace std;


void test01()
{
    char ch = 'c';
    double d = static_cast<double>(ch) ;
    cout<<d<<endl ;

}

class Base{};
class Child:public Base{};
class Other{};

void test02()
{
    //父子之间的转换
    Base * base = nullptr;
    Child * child  = nullptr;
    Other * other = nullptr ;

    //  向下转换，不安全
    Child * child2 = static_cast<Child*>(base);

    //向上转换，安全
    Base * base2 = static_cast<Base*>(child);

    //Other * other2 = static_cast<Other*>(base); //必须在继承关系里面的类之间互相转换

}


//dynamic_cast  
//1.不可以转换基础数据类型（精度丢失或者不安全）
//2.向上转型是安全的，可以用动态类型转换
//3.发生多态的时候，向上，向下类型转换都是安全的，可以用dynamic_cast进行转换



//const_cast  
//1.操作的对象是指针或者引用，其他的不可以

void test03()
{
    //去const
    const int *p = nullptr;
    int *pp = const_cast<int*>(p);

    //加const
    int *p2 = nullptr;
    const int *ppp = const_cast<const int *>(p2);
}


void test04()
{

    int a = 10;
    int *p = reinterpret_cast<int*>(a); //重新解释类型转换，很不安全，不推荐


}

int main()
{   
    //test01();
    //test02();

   


    return 0;
}