#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void test()
{
	char **p = malloc(sizeof(char*) * 5) ;
	if( NULL == p)
		return ;
	int i = 0; 
	for(i = 0;i< 5;++i)
	{
		p[i] = malloc(sizeof(char) *32) ;
		memset(p[i],0,32);
		sprintf(p[i],"name%d",i);
	}


	for(i = 0;i<5;++i)
		puts(p[i]);

	for(i = 0;i<5;++i)
		if(p[i] != NULL)
		{
			free(p[i]);
			p[i] = NULL;
		}

	if(p != NULL)
	{
		free(p);

		p = NULL ;
	}
}


void test2()
{


	char buf[1024]  ={0}; 
	sprintf(buf,"%#o",23);
	printf("buf = %s\n",buf) ;

}
int main(void)
{
	test();

	test2();

	return 0;
}