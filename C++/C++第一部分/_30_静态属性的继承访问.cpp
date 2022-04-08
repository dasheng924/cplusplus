
//不会自动继承的函数：构造函数，析构函数，=运算符，友元函数

#include <iostream>

using namespace std;

class Test{

public:
    void add(){
        num++;
    }

    void show(){
        cout<<"num="<<num<<endl;
    }

    static int num ;

};

int Test::num = 10;

class Dervlie:public Test{
public:

    void Add(){
        num++;
    }
};

//静态数据或者静态函数，同一个类的多个对象之间是共享的，也会被所有的类共享。内存中只有一份拷贝

int main(void)
{

    Dervlie d; //静态数据和静态函数都被继承了
    d.add();
    d.Add();

    d.show();//num=12 ,静态变量的值加了两次


    return 0;
}




