//c++ 中共有4种类型转换、
//1.static_cast<>()  <要转换的目标类型> （被转换的变量）


#include <iostream>

using namespace std;

class Animal{};
class Dog:public Animal{};
class Other{};


//static_cast<>()
void test01(){

    int a = 10;

    // static_cast :基础类型转换；隐式类型转换:void*转指针等，
    //向上转型是安全的，向下转型不是安全的
    double dd = static_cast<double>(a);
    cout<<dd<<endl;

    cout<<typeid(dd).name()<<endl; //d
    //向上类型转换: 子类的指针或者引用转向父类的指针或者引用是安全的

    //---------子类的指针或者引用转向父类，是安全的,向上转型
    Animal * animal = static_cast<Animal*>(new Dog());

    //向下转型,不安全（子类的内存空间占用比父类的大，导致有部分内存会丢掉）
    //Dog * dog = static_cast<Dog*>(new Animal()); 

    //无血缘关系之间的转换,报错，不能转换,只能用于父类和子类之间
    //which are not related by inheritance, is not allowed
    //Animal * animal2 = static_cast<Animal*>(new Other());

    


}

//dynamic_cast<>()
//1.动态类型转换：用于含有虚函数的类，只能用指针或者引用向上转换
//2.向下转换的时候，非法的指针返回NULL，非法的引用，抛出异常，具有类型检查功能，更加安全
class Dogg{
public:
    virtual void showName() = 0;

};

class Dog_W:public Dogg{
public:
    virtual void showName(){
        cout<<"WWW"<<endl;
    }
};




void test02()
{
    //向上转换
    Dogg * dogg = dynamic_cast<Dogg*>(new Dog_W());

}

int main(void)
{
    // test01();
    test02();

    //const_cast<>()常量转换：const ---》非const
    //不能对非指针或非引用进行转换

    const int *p =NULL;

    int *np = const_cast<int*>(p);//

    int *npp = NULL;
    p = const_cast<const int*>(npp);
    
    
    
    //reinterpret_cast:重新解释，不太建议使用
    


    return 0;
}



//static_cast<>() 基础类型转换和隐式类型转换 继承关系中向上类型转换是安全的

//dynamic_cast<>() 要保证基类中存在虚函数，保证多态；用于将基类的指针或者引用转化为派生类的指针或者引用（向下转换）；
//向上转换是安全的。
//向下转换时，dynamic_cast 是有类型检查的，比static_cast 更安全
//类型检查：变量的运行时类型和要转换的类型是否是相同的，判断是否可以转换



//const_cast<>() 常量指针或者引用转换为非常量指针或非常量引用

//reinterpret_cast<>()  重新解释
 
/*

Static_cast是静态转换，也就是编译时转换，可以完成基础类型的转换，然后任意类型指针与void指针的转换，还可以完成同一个继承体系中类型的转换。

 

Dynamic_cast是运行时转换，用于将基类的指针或引用安全的转换成派生类的指针或引用。也就是所谓的downcast，向下转换，因为向上转换upcast是没有问题的（子类转换为父类），因为父类的行为（函数）都包含在子类中。

同时，要保证基类中存在虚函数，保证多态。

 

Const_cast 去除掉常量属性

 

Reinterpret_cast 对二进制形式重新解释，但不改变其值。


*/


/*
static_cast<>() 静态转换:基本数据类型转换和隐式类型转换;同时可以同于父类和子类的向上类型转换

dynamic_cast<>() 动态转换:要求要有虚函数的重写,发生多态. 向上转换是OK的,向下转换,非法指针返回NULL,非法引用抛异常.
-->是把基类指针或者引用转换成派生类对象或者指针.

const_cast<>() 指针类型或者引用类型的去掉const属性

reinterpret_cast<>() 重新解释


*/