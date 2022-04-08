#include <iostream>


using namespace std;

/*

1.const 只读的变量
2.const 常对象:无法修改类的成员变量;只能调用类的const成员函数
3.const 指针:3种









#if 0
//1.const变量:只读常量
//-->表示此变量为只读,不应该被修改(但是也是可以进行修改的)
//-->后续不被修改,所以应该在定义的时候就进行初始化
//-->C++中可以用const 替换 宏,const变量可以提供类型检测,更加安全
//const全局变量只能存在于本文件,要被其他文件访问,需要加上 extern


const int num  =10; //无法修改,全局的const通过指针也无法进行修改

int main(){

    const double fi = 23.1223;

    // num = 111; //error 
    // fi = 78.2312;//error

    double *ptr = (double *)&fi;
    *ptr = 1.1234;
    cout<<fi<<endl;

    //C++11 constexpr 常量表达式:


    cout<<"hello world"<<endl;
    return 0;
}
#endif




//必须要列表初始化的三种方式:
//1.子类继承父类,同时父类有参数的构造函数,这个时候,子类必须调用父类的构造函数进行初始化,同时可以使用C++11 提供的继承构造   using Base::Base;
//2.类中含有const变量和引用就必须进行初始化列表进行初始化
//3.子类初始化父类的私有变量,必须使用列表初始化



#if 1
class Test
{
public:
    Test(int num1,int num2,int num3=0):x(num1) //2.const 成员变量,需要在构造函数的初始化列表处进行初始化;初始化列表会在构造函数的前面进行运行
    {
        this->y = num2;
        this->z = num3;
    }

    //constexpr Test(int num1,int num2,int num3):x(num1),y(num2),z(num3){}

    void show() const
    {
        cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
    }
    void print()
    {
        cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
    }
    int z;

    static const int d = 100;
private:
    const int x;
    int y;
};



int main()
{

    const Test t(1,2); //常对象:1.不能修改类的成员变量  2.只可以调用类的const成员函数
    // t.z = 100;//error 1.不能修改类的成员变量
    t.show();//2.只可以调用类的const成员函数

    exit(0);
}


#endif

