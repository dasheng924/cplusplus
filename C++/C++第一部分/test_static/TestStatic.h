#pragma once



#include <iostream>


using std::cout;
using std::endl;



class TestStatic
{
public:
	TestStatic();
	void func1();
	static void func2();
	static void func3(const TestStatic& obj);


	//常静态函数
	const static int num4 = 99;//又要实现共享，又要不可变，直接类内初始化
	int num1;
	static int num2;//静态成员变量

	
private:
	static int num3;
};

