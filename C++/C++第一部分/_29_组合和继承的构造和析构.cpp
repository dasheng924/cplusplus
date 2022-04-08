#include <iostream>

using namespace std ;

class A
{
public:
    A(){cout<<"A cons"<<endl;}
    ~A(){cout<<"A desc"<<endl;}
};

class B:public A{
public:
    B(){cout<<"B cons"<<endl ;}
    ~B(){cout<<"B desc"<<endl ;}

    A a;
};

int main()
{
    //先继承再组合再自己
   /* 
    A cons;
    A cons;
    B cons;
    B desc;
    A desc;
    A desc;
    */
   B b;
/*
   telecomadmin
   nE7jA%5m3
   ptpjydkc


   13813388779
   
   */



    return 0;
}