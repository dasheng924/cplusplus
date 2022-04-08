#include <iostream>

using namespace std;

template<typename T>
T myPlus1(T a,T b)
{
    return a+b;
}

int myPlus2(int a,int b)
{
    return a+b;
}


void test01()
{
    int a = 10 ;
    int b = 20;
    char c = 'c';

    //myPlus1(a,c); //调用失败，无法类型转换;类型推导不出来
    myPlus2(a,c);

}

template<typename T>
void play(T a)
{
    cout<<"调用模版函数<T>"<<endl ;
}

template<typename T>
void play(T a,T b)
{
 cout<<"调用模版函数<T,T>"<<endl ;   
}


void play(int a)
{
    cout<<"调用普通的函数"<<endl ;
}

void play(int a,int b)
{
    cout<<"调用普通的函数重载"<<endl ;
}


void test02()
{
    //模版函数和普通的函数都符合规则，优先调用普通函数
    //普通函数，直接调用就好，模板需要两次编译
    
    //play(1); // 1.发生重载，优先调用普通的函数

    //2.也可以显式指定调用模板函数
    //play<int>(2);




    //3.函数模板也可以重载
    //play(1,2);

    //4.函数模版可以更好的匹配，会优先调用
    play('a','b'); //模板函数和两次编译

    //第一次编译在模板函数声明的地方
    //第二次编译在替换完之后进行编译

    /*
    1.普通函数和函数模板都可以调用，优先调用普通函数，但是可以显式指定调用模板函数；
    2.如果都可以调用，那个匹配度更高就调用那个
    3.函数模板也可以进行重载



    */



}


int main(void)
{
    //test01();
    test02();

    return 0;
}