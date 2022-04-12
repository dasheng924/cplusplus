#include <stdio.h>
#include <string.h>
void show1(int arr[7])
{
    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void show2(int arr[], int len)
{
    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void show3(int *arr, int len)
{
    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main(void)
{

    int arr[] = {11, 2, 34, 10, 45, 2, 90};
    int len = sizeof(arr) / sizeof(arr[0]);

    show1(arr);
    show2(arr, len);
    show3(arr, len);

    char buf[] = "sdfdsfew";
    // buf 就是字符数组的首元素的地址
    char *p = buf;
    while (*p != '\0')
    {
        printf("%c ", *(p++));
    }
    printf("\n");

    for (int i = 0; i < strlen(buf); ++i)
    {
        printf("%c ", *(buf + i));
    }

    printf("\n");

    return 0;
}