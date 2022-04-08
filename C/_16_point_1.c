#include <stdio.h>


//指针就是一个变量，由值也有地址


int main(void)
{
#if 0
	int a = 10 ;
	printf("a = %d\n",a);
	printf("%p\n",&a);

	int *p = NULL;
	printf(" p = %p\n",p);
	printf("%p\n",&p);

	NULL;//相当于0;

#endif


#if 1


	int a = 10 ;
	int *p = &a ;
	int **q = &p ;


	printf("a = %d\n",a);

	*(*q) = 100 ;

	printf("a = %d\n",a) ;


#endif



	return 0;
}