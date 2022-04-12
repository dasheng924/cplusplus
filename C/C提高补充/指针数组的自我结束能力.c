#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char *str[] = {
        "case",
        "static",
        "switch",
        "while",
        NULL //加入这个就可以在不知道指针数组维数的情况下,可以结束
    };

    for (int i = 0; str[i] != NULL; ++i)
        printf("%s ", str[i]);
    printf("\n");
    return 0;
}
