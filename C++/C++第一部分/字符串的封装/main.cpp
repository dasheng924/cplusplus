//
// Created by 孙国盛 on 2021/5/18.
//

#include "MyString.h"

int main()
{
    //有参构造
    MyString mystring("hello") ;
    mystring.show() ;

    //拷贝构造
    MyString str(mystring);
    str.show();
    //重载<< 操作符
    cout<<str<<endl;

    // = 号初始化
    MyString str2 = "helloece" ;
    cout<<str2<<endl ;
    //= 号两个对象相互赋值，需要重载 = 号运算符
    MyString str3 = str2 ;
    str3.show() ;
    //>> 运算符的重载
    cout<<endl ;
    cin>>str3;
    str3.show();

    //[]

    cout<<"str3的第一个位置是"<<str3[0]<<endl ;

    if(str == str3)
        {cout<<"相等"<<endl ;}
    else
        {cout<<"不相等"<<endl ;}














    return 0;
}