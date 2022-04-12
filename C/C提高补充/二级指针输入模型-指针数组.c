#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showArray(char **p, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%s\n", p[i]);
    }
}

void arraySoft(char **p, int len)
{
    if (p == NULL || len <= 0)
        return;
    char **arr = p;
    for (int i = 0; i < len; ++i)
    {
        for (int j = i; j < len; ++j)
        {
            if (strcmp(arr[i], arr[j]) < 0) //比较的是指针指向的内存空间的值
            {
                char *tmp = arr[i]; //交换的是指针指针
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(void)
{
    char *arr[] = {"aaa", "bbb", "ccc", "ddd"};

    int len = sizeof(arr) / sizeof(arr[0]);

    int len2 = sizeof(arr) / sizeof(*arr);

    printf("%d,%d\n", len, len2);

    //排序
    arraySoft(arr, len);
    showArray(arr, len);
    return 0;
}