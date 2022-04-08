#include <stdio.h>
int main(void)
{
    const int a = 10;
    int *p = &a;
    *p = 11;
    printf("a=%d\n",a);
    return 0;
}