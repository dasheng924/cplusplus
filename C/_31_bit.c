#include <stdio.h>
#include <stdlib.h>


void ji_ou(int num)
{
	
	if((num & 1) == 0)
		puts("偶数");
	else
		puts("奇数");

}


void swap(int *a,int *b)
{
	*a = *a ^ *b ;
	*b = *a ^ *b ;
	*a = *a ^ *b ;
	


}

int  left(int num,int left_num)
{
	return (num << left_num);
}


int  right(int num,int right_num)
{
	return (num >> right_num);
}
int main(void)
{
	int num = 123;
	ji_ou(num);

	int num2 = 443;

	swap(&num,&num2);

	printf("num = %d\nnum2 = %d\n",num,num2);
	

	printf("num = %d\t,left num = %d\n",num,left(num,2));






	return 0;
}