#include <iostream>
using namespace std;

//1.常函数里面不可以修改类的成员变量
//2.常对象只能调用类的常函数，也不能修改类的成员变量
//3.要想修改，必须用mutable修饰

class Test
{
public:
    Test()
    {
        this->m_A = 0;
        this->m_B = 0;
    }

    //1.常函数
    void showInfo(void) const //常函数 ---> //const Test *  const this 
    {
        //不能修改成员变量
        //this->m_A = 100;
        this->m_B = 200 ; 


        cout<<"m_A = "<<this->m_A<<"\tm_B = "<<this->m_B<<endl; 
    }

    void changeInfo(void) const
    {

    }


private:
    int m_A;
    mutable int m_B; //在常函数中依然可以修改值，

};

void test01()
{
    Test t;
    t.showInfo();
}

void test02()
{
    //常对象
    const Test t2; //常对象，不允许修改属性
    t2.changeInfo(); //常对象不能调用普通的成员函数，可以调用常函数

}



int main(void)
{
    


    return 0;
}