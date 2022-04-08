#include <stdio.h>


void test01()
{


	char buf[1024] = {0} ;

	sprintf(buf,"I am %s","JON");
	printf("buf = %s\n",buf) ;
}


void test02()
{
	char buf[1024] = {0};
	int num  = 22 ;
	sprintf(buf,"%d", num);
	printf("buf = %s\n",buf) ;

}
int main(void)
{
	test01() ;

	test02();






	return 0 ;
}