#include <stdio.h>
#include <stdlib.h>
#include <string.h>




extern int a = 10 ; //外部链接
int b ;
static int c = 20;
static int d;


/*

1.外部链接：可以被别的文件引用
2.内部链接：在别的文件中是不可见的，只在当前文件是有效的

a.静态全局变量和静态局部变量都是存储在静态区
b.全局静态变量的生命周期为本文件，局部静态变量的生命周期只存在于当前函数
*/


void func()
{
	static int e = 30 ; //生命周期只存在于本函数

}


int main(void)
{

	printf("extern int a = %d\n",a);
	printf("int b = %d\n",b);
	printf("static int c = %d\n",c);
	printf("static int d = %d\n",d);
	
//	printf("static int e = %d\n",e); //局部静态变量的生命周期存在于本函数




	return 0;
}