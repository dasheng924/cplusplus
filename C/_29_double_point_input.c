
//二级指针做输入参数：主调函数分配内存
#include <stdio.h>
#include <stdlib.h>
#include <string.h>







int main(void)
{


	int *p[5] = {0};

	int i = 0;
	for(i = 0;i<5;++i)
	{
		p[i] = malloc(sizeof(int)*1);
	}

	for(i = 0;i<5;++i)
	{
		memset(p[i],0,sizeof(int));		
		*p[i] = 100+i ;
		printf("*p[i] = %d\n",*p[i]);
	}

	
	for(i = 0;i<5;++i)
	{

		if(p[i] != NULL)
		{
			free(p[i]);
			p[i] = NULL ;
		}

	}

	return 0;
}