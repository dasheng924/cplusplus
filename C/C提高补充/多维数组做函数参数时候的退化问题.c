#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show1(int arr[3][4])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void show2(int arr[][4], int len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void show3(int (*arr)[4], int len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void showOne(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int a[3][4] = {
        {1, 23, 19, 10},
        {67, 2, 78, 43},
        {22, 0, 6, 98}};

    int len = sizeof(a) / sizeof(a[0]);
    show1(a);
    printf("---------------------------\n");
    show2(a, len);
    printf("---------------------------\n");
    show3(a, len);
    printf("---------------------------\n");
    //当成一维数组
    showOne((int *)a, 3 * 4);

    return 0;
}