//const 局部变量和全局变量的区别？

/*
1. const 局部变量
	不可以直接修改，但是可以间接修改
2. const 全局变量
	不可以直接修改，也不可间接修改
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int g_a = 100 ;//常量区


int main(void)
{
	//先看全局const 变量 
	printf("%d\n",g_a);
	//g_a = 200 ;  //直接修改报错
#if 0
	//全局const变量间接修改失败
	int *p = (int*)&g_a ;
	*p = 300 ;
	printf("new g_a = %d\n",g_a) ;
#endif

#if 0
	const int b = 99 ; //局部的const在栈上
	printf("b = %d\n",b);
	 // b = 399 ; //直接修改失败
	int *pp = (int*)&b ;
	*pp = 499 ;
	printf("b = %d\n",*pp) ; //间接修改 OK 


#endif


#if 0
	//字符常量
	char *  p = "hello world" ;  //p在栈区，"hello world" 在常量区
	printf("p = %d\n",p);

	printf("hello world = %d\n",&"hello world");

	/*
		p = 141623172
		hello world = 141623172

	*/

	printf("%s\n",p);
	p[0] = 'H';  //不可修改
	//printf("%s\n",p);


#endif 


#if 1


	char * p1 = "hello" ;
	char * p2 = "hello" ;

	//相同的字符串常量它的地址是一样的吗？

	printf("%p\n",p1) ;
	printf("%p\n",p2) ;

	//0x1069c4fa4
	//0x1069c4fa4

	//编译器优化的结果，节省内存

#endif



	return 0;
}

