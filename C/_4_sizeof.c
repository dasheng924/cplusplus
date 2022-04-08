#include <stdio.h>
#include <string.h>

#ifdef _PACK_
#pragma pack(1) //以1个字节对齐，会影响结构体的大小
#endif
typedef struct Person
{
	int age;
	char name[32];
	char sex;
}PERSON;

//#pragma pack() 取消自定义对齐方式


int main(void)
{
	
	//1.sizeof 返回实际所占的内存大小
	//可以计算数据类型和变量的大小

	size_t num1 = sizeof(int);
	double bb = 2.32;
	size_t num2 = sizeof bb;

	printf("sizeof(int) = %zu\nsizeof bb = %zu\n",sizeof(int),sizeof bb);

	//计算一下结构体的大小

	PERSON p;
	p.age = 22;
	p.sex = 'm';
	strcpy(p.name,"alex");
	

	printf("look struct Person\n");

	printf("name = %s,age = %d,sex=%c\n",p.name,p.age,p.sex);
	printf("sizeof(struct Person):%zu\n",sizeof p);

	
	//sizeof 的返回值是无符号整形

	//size_t   %zu

	float ff = 3.443f;
	
	size_t size = sizeof ff;	//unsigned 的返回值永远是大于0的 
	if(size -100 > 0 )
		puts(">0");
	else if(size -100 < 0)
		puts("<0");
	else
		puts("=0");


	return 0;
}