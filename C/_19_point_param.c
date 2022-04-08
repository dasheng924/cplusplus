
//指针作为函数的参数的输入特性和输出特性  

//输入特性：主调函数分配内存，被调函数形参获取数据
//输出特性：被调函数分配内存，要么是全局变量或者堆上的内存
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void func(int *p)
{
	*p = 100;
}

char * func2(int num)
{
	if(!abs(num))
		return NULL;
	char * p = malloc(sizeof(char)*num) ;
	if(p == NULL)
		return NULL;
	memset(p,0,num);
	strcpy(p,"hello");
	return p ;
}


int main(void)
{
	int a = 10 ;
	printf("old_a = %d\n",a);
	func(&a);
	printf("new_a = %d\n",a);

	//被调函数分配内存

	char *ret = func2(10);
	printf("%s\n",ret);

	return 0;
}