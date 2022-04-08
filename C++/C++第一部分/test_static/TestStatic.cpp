#include "TestStatic.h"





//1.静态变量的初始化,在类内声明，在类外定义，区分作用域控制符

int TestStatic::num3 = 300;
int TestStatic::num2 = 200;

TestStatic::TestStatic()
{
	this->num1 = 100;
}

void TestStatic::func1()
{
	cout << "num1 = " << this->num1 << endl;
	cout << "通过成员函数调用num2 = " << TestStatic::num2 << endl;//类内访问private 
}

//4
void TestStatic::func2()
{
	cout << "类中的静态函数，用于管理类中的静态数据" << endl;
}



//6 静态函数调用非静态成员变量
void TestStatic::func3(const TestStatic& obj)
{
	cout <<"用对象访问非静态变量"<< obj.num1 << endl;
}

