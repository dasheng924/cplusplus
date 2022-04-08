#include <stdio.h>



int main(void)
{
	
	int num = 10;
	for(int i = 0;i< num;++i)
	{
		if(i%2== 0)
			continue;	//直接返回到循环的开头，不会有后面的打印
		printf("num = %d\n",i);
	}


	return  0 ;
}


