#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0 

void alloc(char *p) //这里的形参和test函数中的p不是同一个
{
	p=malloc(100);
	memset(p,0,100);
	strcpy(p,"hello");//改变的只是形参的值
	puts(p);
} //在函数结束时p会被释放

void test()
{
	char * pp = NULL;//在栈上分配内存
	alloc(pp);//没有改变传入的pp的值
	printf("%s\n",pp); //打印出来的还是null
}

#endif

#if 1

//如果要想改变这个传入的值

void my_malloc(char **p)
{
	/*
	p = malloc(100);
	memset(p,0,100);
	strcpy(p,"hello");

	*/
	char * temp = NULL;
	temp = malloc(100);
	memset(temp,0,100);
	strcpy(temp,"hello");
	*p = temp ;
}


void test01()
{
	char * pp = NULL ; 
	my_malloc(&pp);
	printf("%s\n",pp) ;


}





#endif

int main(void)
{
	test01();


	return 0;
}