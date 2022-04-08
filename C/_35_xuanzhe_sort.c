#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void getArr(int arr[],int len)
{
    srand(time(NULL));

    for(int i = 0;i<len;++i)
    {
        arr[i] = 10+ rand()%10 ;
    }
}

//快速排序
void quickSort(int s[],int begin,int end)
{
    if(begin < end)
    {
        int i = begin;
        int j = end;
        //拿出第一个元素,保存到x中，第一个位置成为第一个坑
        int x = s[begin];
        while(i<j)
        {
            //从右向左找小于x的数
            while(i < j && s[j] >= x)
            {
                //左移，直到遇到小于等于x的数
                j--;
            }
            if(i <j)
            {
                //将右侧找到的小于x 的元素放入左侧坑中，右侧出现一个坑
                //左侧元素索引后移
                s[i++] = s[j];
            }
            //从左向右找大于等于x的数
            while(i<j && s[i] < x)
            {
                //右移，直到遇见大于x的数
                i++;
            }
            if(i < j)
            {
                //将左侧找到的元素放入右侧坑中，左侧出现一个坑
                //youce元素索引向前移动
                s[j--] = s[i];
            }

        }
        //此时，i= j，将保存在x中的数填入坑中
        s[i] =x;
        quick(s,begin,i-1);
        quick(s,i+1,end);

    }

}


//插入排序
void insertionSort(int arr[],int len)
{
    if(len <= 0)
        return ;
    int i = 0,j = 0;
    int tmp = 0;
    for(i = 1;i<len;++i)
    {
        tmp = arr[i];
        for(j = i-1;j>=0 && arr[j] > tmp;j--)
            arr[j+1] = arr[j];
        arr[j+1] = tmp ;
    }
}



//冒泡排序
void maopao(int arr[],int len)
{
    if(len <= 0)
        return ;
    int i = 0,j = 0;
    int tmp = 0;
    for(i = 0;i<len-1;++i)
    {
        for(j = 0;j<len-1-i;++j)
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp ;
            }
        }
    }
}


//选择排序
void xuanzhe(int arr[],int len)
{
    if(len <= 0)
        return ;
    int i = 0,j = 0;
    int min  = 0;
    int tmp = 0;
    for(i = 0;i<len-1;++i)
    {
        min = i;
        for(j = i+1;j<len;++j)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            //交换下标为i和min的两个数
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp ;
        }
    }
}


void show(int arr[],int len)
{
    if(len <= 0)
        return ;
    int i = 0;
    for(;i<len;++i)
        printf("%d\t",arr[i]);
    printf("\n");
}




int main(void)
{

    int arr[10];
    unsigned int len = sizeof(arr)/sizeof *arr ;

    getArr(arr,len) ;
    show(arr,len) ;

    xuanzhe(arr,len);
    show(arr,len);

    maopao(arr,len);
    show(arr,len);

    insertionSort(arr,len);
    show(arr,len);

    return 0;
}