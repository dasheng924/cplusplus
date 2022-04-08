//自定义的函数在main函数执行之前就运行
#include <stdio.h>

__attribute__((constructor(101))) void before1();

void before()
{
    printf("hello c\n");
}
int main()
{


    return 0;
}