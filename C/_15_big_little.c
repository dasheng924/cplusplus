
//小端模式：高位放高地址
#include <stdio.h>




void big_little(void)
{

	int num = 1;
	unsigned char * p = (unsigned char *)&num ;

	if(*p)
		puts("little");
	else
		puts("big");

}

int main(void)
{
	int num = 0xaabbccdd;
	unsigned char * p = (unsigned char*)&num ;
	printf("%x\n",*p);
	printf("%x\n",*(p+1));


	big_little();


	return 0;
}
