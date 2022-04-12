#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int trimSpace(char *inBuf/*in*/,char *outBuf/*in*/)
{
    if(inBuf == NULL || outBuf == NULL)
    {
        printf("input null\n");
        return -1;
    }

    char *p = inBuf;

    while( *p++)
    {
        if( *p == ' ')
            continue;
        else
            *outBuf++ = *p;
    }

    *outBuf = '\0';





    return 0;
}


//主要是找出"   saa ded  "  ---> 两头空格的分界点
int trimSpace2(char *inBuf/*in*/,char *outBuf/*in*/)
{
     if(inBuf == NULL || outBuf == NULL)
    {
        printf("input null\n");
        return -1;
    }

    int i=0;
    int j = 0;
    int k = 0;
    char *s = inBuf;
    while( isspace(s[i]) && s[i] != '\0' )
        i++;

    j = strlen(s) -1 ;

    while ( isspace(s[j]) && j >=0)
        j--;

    while( i <= j)
        outBuf[k++] = s[i++];

    outBuf[k] = '\0';

    return 0;
}



int main(void)
{

    char *p = "    ab cdf   ";
    char out[64] = {0};
    trimSpace2(p,out); //trimSpace 对字符串中间含空格的支持不行

    printf("%s\n",out);

    return 0;
}