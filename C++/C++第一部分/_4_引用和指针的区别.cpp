#include <iostream>

using namespace std;

int main()
{
    int a = 100;
    //初始化
    //引用已存在变量的别名
    int &ref_a = a;
    //指针：变量的内存地址（有自己的内存地址）
    int *ptr  = nullptr; //可以赋空值，引用不可以
    ptr = & a;

    //大小
    cout<<sizeof(ptr)<<endl;//8，64位平台，指针的大小
    cout<<sizeof(ref_a)<<endl;//4,引用对象本身的大小

    //指针在使用过程中可以改变指向，引用只能是一个对象的引用
    //指针可以有多级，引用就只有一级
    //指针的++操作和引用的++ 操作是不一样的

    //建立对数组的引用
    using arrTYpe = int[10];
    int arr[10] = {0};
    arrTYpe &pp = arr;

    for(auto i:pp)
    {
        cout<<i<<" ";
    }
    cout<<endl;




    return  0;


}