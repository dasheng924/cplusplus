/*

1.const 定义的常量有类型检查  ，#define 定义的宏常量没有类型检查，只是简单的替换

2.#define 在预处理阶段就会替换，const在运行时检查

3.const注重作用域，#define 一般从定义到文件结尾
*/

#include <cstdio>

#define PARAM  128

// #undef PARAM 
const short param = 128;

void func(int num)
{
    printf("func int\n");
}
void func(short num)
{
    printf("func short\n");
}


int main(void)
{

#if 1
    func(param);   //func short  这个会有类型的匹配
    func(PARAM);   //func int

#endif


    return  0; 
}