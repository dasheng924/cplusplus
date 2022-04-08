#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void test()
{


	char * p  = calloc(3,1);

	int i = 0 ;
	
	p[0] = 'h';
	p[1] = 'o';
	p[2] = 'e' ;

	printf("%s\n",p);


	if(p  != NULL)
	{
		free(p);
		p = NULL;
	}


	printf("%p\n",p);
	p = realloc(p,300);//可能会重新分配内存，p 的地址会不一样
	printf("%p\n",p);

}

int main(void)
{
	test();
	


	return 0;
}




