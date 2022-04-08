#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;



template<class T>
void print(T val)
{
    cout<<val<<"\t" ;
}

template<class T>
void show(deque<T> &d)
{
    cout<<endl;
    for(/*typename deque<T>::iterator*/auto it = d.begin();it != d.end();++it)
    {
        cout<<*it<<"\t";
    }
}

//deque 的初始化
void test01()
{
    deque<int> d1;
    for(int i = 0;i<10;++i)
    {
        d1.push_front(i);
    }
    for(int i = 100;i<110;++i)
    {
        d1.push_back(i);
    }
    show<int>(d1);

    /*
deque<T> deqT;//默认构造形式
deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);//构造函数将n个elem拷贝给本身。
deque(const deque &deq);//拷贝构造函数。
     */
    deque<int> v2(10,2);
    show<int>(v2);

    deque<int>v3(v2);
    show<int>(v3);
}

//deque 赋值操作
void test02()
{
    /*
    assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
    assign(n, elem);//将n个elem拷贝赋值给本身。
    deque& operator=(const deque &deq); //重载等号操作符
    swap(deq);// 将deq与本身的元素互换
     */

    deque<int> v1;
    v1.assign(10,9);
    show<int>(v1);

    deque<int> v2 = v1;
    show<int>(v2);
}

//deque 大小操作
void test03()
{
    deque<int> v1;
    for(int i = 0;i<12;++i)
    {
        v1.push_front(i+10);
    }

    cout<<"deque v1的大小"<<v1.size()<<endl; //没有容量的函数
//    bool  ret = v1.empty(); //返回false ，证明有元素
//    cout<<ret<<endl;
    cout<<"deque v1是否为空："<<((v1.empty() == false)?"不为空":"为空")<<endl;

    ////重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
    v1.resize(20);
    show<int>(v1);
    //21	20	19	18	17	16	15	14	13	12	11	10	0	0	0	0	0	0	0	0
    //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
    v1.resize(3, 99);
    //21	20	19
    cout<<"deque v1的大小"<<v1.size()<<endl; //没有容量的函数
    show<int>(v1);



}

//deque 双端插入删除
void test04()
{
    deque<int> d1(5,99);
    show<int>(d1);

    d1.push_front(1);
    d1.push_back(1);
    show<int>(d1);

    d1.pop_back();
    d1.pop_back();
    d1.pop_front();

    show<int>(d1);




}

bool myCompar(int a,int b)
{
    return a>b;
}
void test05()
{
    //sort
    deque<int> d;
    d.push_back(12);
    d.push_back(1);
    d.push_back(31);
    d.push_front(44);

    sort(d.begin(),d.end());
    show<int>(d);
    sort(d.begin(),d.end(),myCompar);
    show<int>(d);



}


int main() {
//   test01();
//    test02();
//    test03();
//    test04();


    test05();
    return 0;
}
