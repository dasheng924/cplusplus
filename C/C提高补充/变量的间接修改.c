#include <stdio.h>

int main(void)
{   

    int num = 100;

    //查看num的内存地址,也就是内存的编号
    printf("num:%p\n",&num);
    //0x7ff7bab11328
    //0x7ff7b0b28328
    //0x7ff7b8223328
    //每次执行程序的时候,num的内存地址都是不一样的

    //(int*)(&num) -->转化为一个整型的地址
    //给上面的内存地址写入数据
    *(int*)(&num) = 111;
    printf("num=%d\n",num); //间接修改内存里面的数据之后
    //num=111

    return 0;
}