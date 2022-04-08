#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int callocSpace(int **ptr)
{
	if(ptr == NULL)
		return -1;
	int *tmp = malloc(sizeof(int)*5);
	memset(tmp,0,sizeof(int)*5);
	for(int i = 0;i<5;++i)
	{
		tmp[i] = i+1;
	}
	*ptr = tmp ;
	return 1;
}

void show(int **ptr)
{
	if(ptr == NULL)
		return ;

	for(int i = 0;i<5;++i)
		printf("%d\n",(*ptr)[i]);//*ptr 只是获取到对应的堆首地址,(*ptr)[i] 这样才获取到对应的元素值

}

void freeSpace(int ** ptr)
{
	if(NULL == ptr)
		return;
	if(*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL ;
	}
}




void test()
{
	
	int * p = NULL ;//被调函数分配内存
	int ret = callocSpace(&p);
	if(ret == -1)
		return ;
	printf("callocSpace ok!\n");
	show(&p);
	freeSpace(&p);
	if(p == NULL)
		puts("freeSpace ok!\n");
}


int  main(void)
{
	test();


	return 0;
}