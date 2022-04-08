//宏函数和普通函数的对比




#include <stdio.h>

//宏的替换开销较小，但只局限于小的语句
#define ADD(x,y) ((x)+(y)) //单纯的替换,在一定的情况下，宏的效率要高

//宏在预处理阶段开始执行替换，函数的参数涉及到入栈和出栈的操作，


//函数的入栈 出栈的操作
//在所由的函数参数入栈成功时，会记录对应的返回地址，也就是函数调用下一条语句的位置
//所有的形参运算完毕时，会先进行出栈的操作
//频繁的调用，短小的函数，可以用宏函数来代替
//参数顺序是主调方和被调方保持一致
int  func(int x1,int x2)
{
	return (x1+x2);
}


int main(void)
{
	int a = 10;
	int b = 20 ;
	int ret1 = 0;
	ret1=ADD(a,b);

	int ret2 = func(a,b);
	printf("ret1 = %d\nret2 = %d\n",ret1,ret2);


	return 0 ;
}