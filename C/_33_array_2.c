//一维数组

#include <stdio.h>


void show(int p[],int len)
{
	for(int i = 0;i< len;++i)
	{	
		printf("%d\n",p[i]) ;

	}

}


void test1()
{
	//定义一个指向数组的指针

	int arr[5] = {1,23,34,4};

	//1.先定义数组类型，再定义数组指针类型
	typedef int (ARRAY)[5] ;
	ARRAY *p = NULL ;
	p = &arr; //&arr 这个是需要对整个数组取地址


	//*(*p+1)  先拿数组，再到数组里面
	//如何用整个p来操作整个数组

	for(int i = 0;i< 5;++i)
	{
		printf("%d\n",*(*p+i)) ;
	}
}

//2.直接定义一个数组指针，可以拿这个类型定义其他的
void test2()
{
	int arr[5] = {2,23,45,22};
	typedef int (*PARR)[5] ;
	PARR p = &arr;
	for(int i = 0;i< 5;++i)
	{
		printf("%d\n",*(*p+i));

	}

}
//3.直接定义数组指针类型，不可以拿这个定义其他类型
void test3()
{
	int arr[5] = {32,2,46,87,9};
	int (*pArray)[5] = &arr;
	for(int i = 0;i<5;++i)
		printf("%d\n",*(*pArray+i)) ;

}


void showp()
{
	puts("-------------------\n");
}
int main(void)
{


	test1();
	showp();
	test2();
	showp();
	test3();


	return 0;
}