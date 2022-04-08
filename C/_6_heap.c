#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * func(void)
{
#if 0
	//在栈上分配内存
	char name[32] = {0};

	strcpy(name,"alex");
	printf("name = %s\n",name);	
	return name ;	//栈区在函数结束后，后释放掉在生命周期内声明的变量
#endif

//在堆上分配
	char * ptr = NULL;
	ptr = malloc(sizeof(char) * 32);

	if(ptr == NULL)
		return NULL;
	memset(ptr,0,32);
	strcpy(ptr,"Lucy");

	return ptr;
}



int main()
{

	char * show  = func();
	puts(show);
	


	return 0;
	
}