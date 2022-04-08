
//const 的使用场景


#include <stdio.h>


typedef struct Person
{
	char name[64];
	int age ;
	int Id ;
	double score;
}Person;

//1.对于一般指针对象的打印，都是传指针的，传的是原对象的地址，但是有修改原数据的隐患



void PrintStruct(const Person * p)
{
	
	printf("%s\n%d\n%d\n%lf\n",p->name,p->age,p->Id,p->score);
}






int main(void)
{
	Person p = {"alex",23,22133,89.32};

	PrintStruct(&p);



	return 0;
}