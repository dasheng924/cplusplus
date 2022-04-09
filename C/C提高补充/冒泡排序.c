#include <stdio.h>


/*
比较相邻的元素。如果第一个比第二个大，就交换他们两个。
对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
针对所有的元素重复以上的步骤，除了最后一个。
持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
*/

void show(int arr[], int len)
{
    int i = 0;
    for (; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


void bobbluSort(int arr[],int len)
{
    //n个数字排序需要n-1次

    int i,j,tmp;
    for(i=0;i<len-1;++i)
    {
        for(j=0;j<len-1-i;++j) //需要交换排序的数量在减少,i就代表了已经排好的序列
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}



int main(void)
{

    //初始化一个数组
    int arr[] = {12, 2, 2,0,6, 23, 100, 1};

    unsigned int len = sizeof(arr) / sizeof(arr[0]);
    show(arr, len);

    bobbluSort(arr,len);
    show(arr,len);

    return 0;
}