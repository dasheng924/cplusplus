#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(char p[10][30], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%s ", p[i]);
    }
    printf("\n");
}

void show2(char p[][30], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%s ", p[i]);
    }
    printf("\n");
}

void sort(char p[][30], int len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = i; j < len; ++j)
        {
            if (strcmp(p[i], p[j]) < 0)
            {
                char tmp[30];
                strcpy(tmp, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], tmp);
            }
        }
    }
}

int main(void)
{

    char array[10][30] = {
        "aaaaa",
        "bbbbb",
        "ccccc",
        "ddddd"};

    int len1 = sizeof(array);
    int len2 = sizeof(array[0]);
    int size = len1 / len2;

    // printf("%s\n", *(array + 1));
    // printf("%s\n",array[1]);
    // printf("%c\n",*(*(array+1)+1));
    // printf("%c\n",array[1][1]);

    sort(array, size);
    show2(array, size);

    return 0;
}