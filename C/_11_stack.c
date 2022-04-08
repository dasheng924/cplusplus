#include <stdio.h>



//stack内存的数据在函数返回时，会被释放掉


char * GetStr()
{
	char * p = "hello" ;
	printf("%s\n",p) ;
	return p;
}



int main(void)
{
	char *pp = GetStr() ;
	printf("%s\n",pp);

	return  0;
}