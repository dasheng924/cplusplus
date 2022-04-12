#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{

    int a[3][5] = {0};

    //给a赋值
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            a[i][j] = i * j;
        }
    }

    //打印数组
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // a 代表什么?  a+1代表什么
    //  a+1 的步长是 5 *4 = 20个字节,它的行为就是一个数组指针的行为
    //  每次往后跳就是跳一个维度的字节
    printf("a %d,a+1 %d\n", a, a + 1);

    // (a+i) 代表的就是整个第i行的首地址
    // *(a+i) 代表第i行的首元素的地址,只不过第i行的整个行的地址和这个行的首元素地址是重合的
    // *(a+i)+j ==> &a[i][j] 代表的是第i行j列元素的地址
    // *(*(a+i)+j) ==> a[i][j] 代表的是i行j列元素的值

    printf("&a %p,&a+1 %p\n", &a, &a + 1);

    return 0;
}