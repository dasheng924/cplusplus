#include <stdio.h>
#include <string.h>

void copy(char *from, char *to)
{
    //不断的改变形参的指向
    for (; *from != '\0'; from++, to++)
        *to = *from;
    *to = '\0';
    return;
}

int main()
{

    char a[] = "I am a student";
    char b[64];

    copy(a, b); //主调函数分配内存
    printf("b=%s\n", b);
    
    return 0;
}