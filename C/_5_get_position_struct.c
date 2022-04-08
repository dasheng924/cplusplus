#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//根据结构体的组成，通过指针的方式获取结构体成员变量的值

typedef struct Person
{
	int age;
	char name[32];
	char sex;
}MyPerson;

int main(void)
{
	MyPerson p;
	p.age = 22;
	strcpy(p.name,"alex");
	p.sex = 'm';

	printf("sizeof(p) = %zu\n",sizeof p);
	MyPerson * ptr = &p; 

	printf("sizeof(ptr) = %zu\n",sizeof ptr);

	//指针偏移的方式获得sex的值

	printf("结构体的首地址:%p\n",ptr);
	//偏移 ((char*)ptr+36)
	
	printf("((char*)ptr+36)  = %p\n",(char*)ptr+36);
	
	char get_ch = *((char*)ptr+36);
	printf("偏移之后获取到的值:%c\n",get_ch) ;

	if('m' != get_ch)
		puts("no no ...");
	puts("good");
	


	exit(0);
}