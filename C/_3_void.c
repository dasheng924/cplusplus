//void 的用法



#include <stdio.h>

void fun(void)
{
	printf("hello\n");
}



int main(void)
{
	//1.不可用来定义类型
	//void num ;//err 不确定分配内存的大小
	void * p ; //可以正常编译通过
	
	int * pInt = NULL;
	//2.数据结构的封装，int 类型的指针不需要强制转换 就可以赋值给void*
	p = pInt ;

	//2.作为函数参数和返回值
	fun();

	return 0;
}


