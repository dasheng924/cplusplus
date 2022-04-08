
//heap 的使用

#include <stdio.h>
#include <stdlib.h>

int * GetNum(void)
{	
	int * ret = malloc(sizeof(int) * 20);//20个int大小的空间
	if(ret == NULL)//判断空间的有效性
		return NULL;
	int i  = 0;
	for(i = 0;i<20;i++)
	{
		*(ret+i) = i+1; //每一个int的内存块中存取的值
	}

	return ret;
}

void play(void)
{
	int *ret = GetNum();
	for(int i = 0;i<20;i++)
	{
		printf("%d\n",*(ret+i));
	}


	free(ret);//需要释放内存
	ret = NULL;
}


int main(void)
{
	play();

	return 0;
}