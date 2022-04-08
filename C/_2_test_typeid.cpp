#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;



typedef int type_int;
int main(void)
{
	cout<<"hello world"<<endl;

	cout<<typeid(type_int).name()<<endl;

	char * p = nullptr;
	cout<<typeid(p).name()<<endl;

	//看一下typeid().name()返回的是什么类型

	cout<<typeid(typeid(p).name()).name()<<endl;


	return 0;
}