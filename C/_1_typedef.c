//typedef 的使用方法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int type_int; //定义已知类型

//C++ 中可以使用using 直接来为已知类型起别名
//using MY_INT = int ;

typedef struct Person
{
	int age;
	char name[32];
}MyPerson;


int main(void)
{
#if 0
	//替代已知类型

	type_int num  = 0;
	printf("input num:\n");
	scanf("%d",&num);

	printf("num = %d\n",num);
	
#endif

//初始化
	MyPerson p ;
	p.age = 22;
	strcpy(p.name,"alex");

	printf("name:%s\n",p.name);	
	printf("age:%d\n",p.age);
	
	//定义一个结构体指针变量
	MyPerson * ptr = NULL;

	ptr = &p;
	printf("name = %s\n",ptr->name);
	printf("age = %d\n",ptr->age);
	


#ifdef _DEBUG_
	//gcc 编译宏的使用
	printf("test typedef\n");
#endif
	exit(0);
}