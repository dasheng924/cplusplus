#include <iostream>
using std::cout;
using std::endl;

//1.C++ 需要对全局变量进行初始化
int a;

/* 2.类型检测的增强
int func1() ; //返回值为int,参数任意  C


//C++ 代表都没有参数
int func2();
int func3(void) ;

*/


//3.相互赋值的时候不同类型需要强转

void test()
{
    typedef enum Color{GREEN,RED,BLACK} color ;

   // color myColor  = 10; //类型不一致，需要强转
   color mycolor = (color)10;
    cout<<mycolor<<endl ;
}

//4. struct 的加强
struct Person
{
    char name[32] ;
    int age ;
};


void test02()
{
   Person p  = {"alex",22} ;   //不需要写struct 关键字
   cout<<"name: "<<p.name<<"\tage: "<<p.age<<endl; 
}


//5.新增bool类型和true（非0）和false两种取值

void test03()
{
    bool isOk = true ; //true 1  false 0 

    cout<<isOk<<endl; 
}

int main(void)
{
    cout<<a<<endl ;

    test() ;
    test02() ;

    test03() ;

    return 0 ;
}