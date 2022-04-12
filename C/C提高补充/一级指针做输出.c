#include <stdio.h>
#include <string.h>

int func(char *fileName, int *fileLen)
{
    int ret = 0;
    ret = strlen(fileName);
    *fileLen = ret;
    return ret;
}

int main(void)
{

    int len = 0;
    int ret = func("abcdedwdwdwdwdwdfg", &len);

    printf("len = %d\n", len);

    return ret;
}