#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//测试字符串相关函数

int main(void)
{

#if 0
    char str1[] = "adwd";
    char str2[] = "dqwdwqadw";
    int i = strspn(str1,str2);
    printf("%d\n",i);

    //也即是str1中的几个字符在str2中出现过
#endif

    char sp[] = "abd-cd-e : :hg";
    char *delim = "-: d"; //- 空格 :

    char *p = NULL;

    printf("%s\n", strtok(sp, delim));

    while ((p = strtok(NULL, delim)))
    {
        printf("%s ", p);
        printf("\n");
    }
}