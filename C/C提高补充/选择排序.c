#include <stdio.h>
/*
首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
重复第二步，直到所有元素均排序完毕
*/


void show(int arr[], int len)
{
    int i = 0;
    for (; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectSort(int arr[], int len)
{
    int i=0,j=0;

    for(int i = 0;i<len-1;++i) //n个数字排序需要走n-1趟
    {
        int min = i; //可以选择第一个数为最小数

        for(int j = i+1;j<len;++j) //剩下的数字进行排序
        {
            if(arr[j] <= arr[min])
            {
                //下标交换
                min = j;
            }
        }

        //最小的数和假设最小的数进行交换
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}

int main(void)
{

    //初始化一个数组
    int arr[] = {12, 2, 2,0,6, 23, 100, 1};

    unsigned int len = sizeof(arr) / sizeof(arr[0]);
    show(arr, len);

    selectSort(arr,len);
    show(arr,len);

    return 0;
}



/*
1.冒泡比较的时候,是两两直接比较交换,交换次数相对较多;选择比较的时候,是拿第一个元素和剩下序列中最小的交换,交换次数是减少的

2.选择根据位置找数,冒泡根据数字本身比较找数

冒泡|选择
时间复杂度为：O( n^2 )
空间复杂度:O(1)
*/