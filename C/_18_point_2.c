//指针的间接赋值



/*
   1.指针越界问题
   2.开辟内存的首地址不能改变
   3.局部变量的地址不能返回🔙
   4.free 后的置空


*/
#include <stdio.h>
void change(int*p)
{
	*p = 999;

}

void func()
{

	int num = 99 ;
	change(&num);
	printf("num = %d\n",num) ;
	
}


void change_point(int **p)
{
	*p = 0xab12;
}


void func2()
{
	int * p = NULL;
	printf("%#x\n",p) ;
	change_point(&p);

	printf("%#x\n",p);
}

int main(void)
{

	func();

	func2() ;

	return 0;
}