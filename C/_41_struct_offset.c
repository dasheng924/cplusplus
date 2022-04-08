#include <stdio.h>

//#pragma pack(show) 

struct Test
{
    int a; //1.第一个元素的偏移是0，与首地址保持一致 0-3
    char b;//2.第二个元素的本身字节是1 与默认对齐字节为8 比较，取最小值 为1 ，4-7
    double c; //3.第三个元素的本身字节是8 ，与默认对齐字节数一致为8 ，选8的倍数，8-15，故上面为4-7
    float d; //4. 4 与 8 比较，选4 ，16-19   
    //总共就是0-19  ，20个字节
};
//结构体整体的偏移量为 元素的最大值8和 默认对齐字节数比较8，取8，最终的字节数必须是8的倍数，离20最近的为24
//把最后的float d 改成double d ，字节总数还是24 
int main(void)
{

    printf("%lu\n",sizeof(struct Test)) ;
   

    return 0;
}