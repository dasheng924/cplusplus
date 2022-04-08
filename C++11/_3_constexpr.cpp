#include <iostream>
using namespace sdt;


//只读和常量 这两个概念是不一样的

int func(const int num)//num是一个只读变量
{
    const int count = 22;//count 是一个常量

    //定义一个数组
    //int array[num];//error,静态数组不能以变量做数组大小
    int array[count];//ok

    //引用的例子
    int a1 = 100;
    int a2 = 200;

    const int &b = a1; //b 作为a1 的别名,不可以通过b修改a1
    //b = a2;//error

    a1 = 1314;
    cout<<b<<endl; //b = 1314,可以通过a的修改影响到b
}

int main(void)
{
    //constexpr 用来修饰常量，常量在编译阶段就确定了值





    exit(0);
}

/*

#include <iostream>
using namespace std;

struct People{
    const char * name;
    int age;
};

//定义一个函数模板
template<typename T>
constexpr T show(T t){
    return t;
}

int main()
{
    People p{"apple",12};

    //普通函数
    People ret = show(p);//p是变量，实例化后的函数不是一个constexpr表达式函数
    cout<<"name = "<<ret.name<<"\tage = "<<ret.age<<endl;

    //表达式常量函数
    constexpr int ret1 = show(250);  //常量表达式
    cout<<"ret1 = "<<ret1<<endl;

    //常量结构体实例
    constexpr People p2{"good",23};
    constexpr People p3 = show(p2);
    cout<<"p3.name = "<<p3.name<<"\tp3.age = "<<p3.age<<endl;

    return 0;
}



*/