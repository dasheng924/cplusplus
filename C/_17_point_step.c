//指针的步长,指针变量+1 的时候往后跳多少个字节

//指针的类型决定了  从给定的位置往后跳的字节数,也决定了 解引用之后一次性读取的字节数
#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct Person{

	int a;
	char b;
	char buf[32];
	int d ;

}Person;



#define OFFSETOF(struct_name,member_name)      (int)&(((struct_name*)0 )->member_name)





int main(void)
{

#if 0
	char * p = NULL;
	printf("%d\t%d\n",p,p+1);

	int *q = NULL;
	printf("%d\t%d\n",q,q+1);
#endif


#if 0

	char buf[1024];
	memset(buf,0,sizeof(buf));

	int a = 100;
	memcpy(buf+1,&a,sizeof(int));

	char * p = buf ;
	p++; //取到存取a值的首地址

	//取出100

	int ret  = *(int *)p;
	printf(" *(int*)p  = %d\n",ret) ;


#endif


#if 1


	Person p = {10,'a',"hello world",99};


	//取到d的值

	Person * ptr = &p ;
	//offsetof这是一个宏函数
	int ret_d = *((int *)((char*)ptr+offsetof(Person,d))) ;

	printf("ret_d = %d\n",ret_d);
	
	//d 的偏移量
	int off_size = OFFSETOF(Person,d);
	printf("off_size = %d\n",off_size);

#endif

	




	return 0;


}