
#include <stdio.h>




int main(void)
{
	
	//定义二维数组
	int arr[3][3] = 
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};


#if 0
	for(int i = 0;i< 3;++i)
	{	
		for(int j = 0;j<3;++j)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
#endif


#if 1
	
	int (*pArr)[3] = arr;

	for(int i = 0;i<3;++i)
	{
		for(int j = 0;j<3;++j)
		{
			printf("%d ",*(*(pArr+i)+j)) ;
		}
		printf("\n");
	}

	

#endif




	return 0;
}