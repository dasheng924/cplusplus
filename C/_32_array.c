//一维数组

#include <stdio.h>


void show(int p[],int len)
{
	for(int i = 0;i< len;++i)
	{	
		printf("%d\n",p[i]) ;

	}

}

int main(void)
{
	//1-以下两种情况，数组名和指针不对等

	//sizeof 
	//&array


	int arr[] = {2,3,3,31,34};

	printf("sizeof(arr) = %zu\n",sizeof(arr)); //20字节 不是指针的8字节

	//步长的问题
	//int * p ;p++ 的话是跳4个字节
	//&arr+1  跳的是整个数组

	printf("(&arr -(&arr+1)) = %ld\n",(&arr+1) - &arr) ;
	printf("%d %d\n",0x64,0x50) ;



	//2-数组名退化为指针的时候，是一个常量指针
	
	
	show(arr,sizeof(arr)/sizeof(*arr)) ;
	show(arr,sizeof(arr)/sizeof(arr[0]));







	return 0;
}