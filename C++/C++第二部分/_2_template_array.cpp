//利用模版实现int char 数组的排序   

#include <iostream>

using namespace std;
template<typename T>
void SWAP(T &a,T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

//排序
template<typename T>
void mySort(T arr[],int len)
{
    for(int i = 0;i<len;++i)
    {
        int max = i;
        for(int j = i+1 ;j < len;++j)
        {
            if(arr[max] < arr[j])
            {
                max = j;
            }
        }
        if(max != i)
        {
            SWAP(arr[max],arr[i]);
        }
    }
}

//打印
template<typename T>
void show(T arr[],int len)
{
    for(int i = 0;i< len;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void test01()
{
    char arr1[] = "jefrfrfefe";
    int len = sizeof(arr1)/sizeof(*arr1);

    show<char>(arr1,len) ;
    mySort<char>(arr1,len) ;
    show(arr1,len) ;
}
void test02()
{
    int arr2[] = {1,3,5,4,6,24,535,2 };
    int len = sizeof(arr2)/sizeof(*arr2) ;

    show(arr2,len);
    mySort<int>(arr2,len) ;
    show<int>(arr2,len);
}


int main()
{

    //test01();
    test02();

    return 0;
}