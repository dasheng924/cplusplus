#include "TestStatic.h"

//5
//静态成员 在编译的时候已经分配内存，那个时候对象还没有创建,编译期间已经确定
//所以静态成员函数是不有 this指针的
//类内声明，类外定义
// className::static_func    className::static_value

//静态成员变量在各个对象中传递信息,因为可以直接调用  类名::静态函数
//静态成员函数用来管理静态变量


//----------------------
//1.静态全局变量
static int dd;//静态区（全局区）.bss;=0;定义到文件结尾
//静态全局变量:
//存储在静态全局区,未经初始化初始值为0,声明周期从定义处到文件的结尾

namespace TT
{

	//2.静态局部变量
	static int dd2;//静态区（全局区）.bss;=0;
	//声明周期从定义处到当前作用域结束
	//作用域结束也不会销毁，会直到程序结束,所以再次被调用的时候，值是不变的
	//未初始化也会初始值为0
}


//3.静态函数：限制在本文件使用，在别的文件中不可调用,内部连接的属性
//不要在CPP中声明 非static 全局函数
//不要在H中声明static函数
//这样就不会产生命名冲突

static void sfunc1() {

	cout << " global static func" << endl;

	cout << " TT " << TT::dd2 << endl;

}








int main(void)
{

	TestStatic ts1;
	//调用static var
	cout << "通过对象直接调用" << ts1.num2 << endl;
	cout << "通过类的作用域调用" << TestStatic::num2 << endl;
	ts1.func1();

	cout << "dd = "<<dd << endl;

	sfunc1();

	TestStatic::func2();
	TestStatic::func3(ts1);

	cout << "出了作用域访问局部static变量 dd = " << TT::dd2 << endl;

	cout << "const static value = " << ts1.num4 << endl;


	return 0;
}
