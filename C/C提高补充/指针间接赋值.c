#include <stdio.h>

void func(int *p)
{
    *p = 1;
}

void func2(int **p) 
{
    *(*p) = 999; //*p找到main中的p,**p才会找到最开始的num
}
int main(void)
{

    int num = 10;
    printf("num=%d\n", num);
    func(&num);
    printf("num=%d\n", num);

    //----------
    int *p = &num;
    func2(&p);
    printf("num=%d\n", num);


    return 0;
}