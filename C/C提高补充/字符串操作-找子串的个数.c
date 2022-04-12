#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char *str = "daaghdddhgdwghdwghdwwdgdwghdwghdw";
    char *p = "gh";
    int ncount = 0;
    do
    {
        str = strstr(str, p);
        if (str != NULL)
        {
            ncount++;
            str += strlen(p);
        }
        else
            break;
    } while (*str != '\0');

    printf("%d\n", ncount);

    return 0;
}