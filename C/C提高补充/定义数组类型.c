#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{

    typedef int(MyArray)[3] ;

    MyArray array;

    for(int i = 0;i<3;++i)
        array[i] = i+1;

    for(int i = 0;i<3;++i)
        printf("%d ",array[i]);
    printf("\n");



    return 0;
}