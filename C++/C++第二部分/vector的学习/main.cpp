#include <iostream>
#include <vector>



//单端数组，动态数组
using namespace std;

void show(int val)
{
    cout<<val<<"\t";

}
/*
* 而是一块更大的内存空间，然后将原数据拷贝新空间，并释放原空间。
* 因此，对vector的任何操作，一旦引起空间的重新配置，指向原vector的所有迭代器就都失效了
*/
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10;i ++){
        v.push_back(i);
        cout << v.capacity() << endl;  // v.capacity()容器的容量
    }

}

//vector基本的初始化
void test02()
{
/*
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。
*/
    int array[] = {1,3,3,44,42,0};
    vector<int> v1(array,array+sizeof(array)/sizeof(*array)) ;

    vector<int> v2(10,1);

}

//赋值
void test03()
{
    /*
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
     */

    vector<int> v1(10,2);
    vector<int> v2;
    v2.assign(v1.begin(),v1.end()); //将[beg, end)区间中的数据拷贝赋值给本身。
    v2.assign(2,100);
    v2.swap(v1);
    for_each(v2.begin(),v2.end(),show);

}

//vector的大小操作
void test04()
{
    /*
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
     */
#if 0
    vector<int> v1(5,12);
    for_each(v1.begin(),v1.end(),show);
    cout<<endl<<"元素个数"<<v1.size()<<endl;
    cout<<"容器是否为空\t"<<((v1.empty() == 0 )? "不是空":"是空")<<endl;
    cout<<"容器的容量"<<v1.capacity()<<endl;

    v1.resize(8);
    cout<<"-------------------"<<endl;
    for_each(v1.begin(),v1.end(),show);
    cout<<endl<<"元素个数"<<v1.size()<<endl;
    cout<<"容器的容量"<<v1.capacity()<<endl;

#endif

#if 1
    vector<int> vv;
    vv.reserve(5);
    for_each(vv.begin(),vv.end(),show);
    cout<<"\n"<<vv.size()<<endl;
    cout<<vv.capacity()<<endl;



#endif






}
//利用swap来收缩空间
void test05()
{
    vector<int> v1;
    for(int i = 0;i<100000;++i)
    {
        v1.push_back(i);
    }

    cout<<"v1的元素个数"<<v1.size()<<endl;
    cout<<"v1的容量"<<v1.capacity()<<endl;
    /*
     * v1的元素个数100000
     *  v1的容量131072
     */
    v1.resize(10);
    vector<int>(v1).swap(v1);//执行之后，容量和元素个数保持一致
    //vector<int>() 是一个匿名对象，通过v1进行拷贝构造，拷贝出来的是一个正常的
    //vector<int>(v1).swap(v1); //也就是匿名对象指向了容量为13万的，v1指向了新开辟的容量为10的空间
    cout<<"v1的元素个数"<<v1.size()<<endl;
    cout<<"v1的容量"<<v1.capacity()<<endl;

    v1.resize(10);
    

}

//reserve 提前预留大空间，方便后续直接插入数据，减少 开辟内存次数，
//前提：大概知道要插入的数量；针对的是大量数据
void test06()
{

    vector<int> v1;
    v1.reserve(60000);  //可以明显减少内存开辟的次数
    int * p = nullptr;
    int num = 0;
    for(int i = 0;i<100000;++i)
    {
        v1.push_back(i);
        if(p != &v1[0]) { //每一次重新的拷贝首地址就会发生改变
            p = &v1[0];
            num++;
        }
    }
    cout<<"插入这些数据，开辟空间的次数是"<<num<<endl;


    // int *p = nullptr;
    // for(int i=-0;i<1000000;++i)
    // {
    //     v1.push_back(i);
    //     if(p != &v1[0])
    //     {
    //         p=&v1[0];
    //         num++;
    //     }
    // }


}

//数据的存储
void test07()
{
    /*
     * at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素
     */

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(100);
    cout<<v1.front()<<endl;
    cout<<v1.back()<<endl;
}

//数据的插入
void test08()
{
    /*
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素
     */

    vector<int> v1;

    v1.insert(v1.begin(),3 ,10);//迭代器指向位置pos插入count个元素ele.
    v1.pop_back();//删除最后一个元素
    v1.erase(v1.begin());//删除迭代器指向的元素

    for_each(v1.begin(),v1.end(),show);


}

//逆序遍历
void test09()
{
    vector<int> v1;
    for(int i = 0;i<10;++i)
    {
        v1.push_back(i);
    }

    for_each(v1.begin(),v1.end(),show);
    cout<<endl;
    //for_each(v1.rbegin(),v1.rend(),show);

    for(vector<int>::reverse_iterator it = v1.rbegin();it != v1.rend();++it)
    {
        cout<<*it<<endl;
    }

}

int main()
{
//    test01();
//    test03();
//    test04();
   test05();
//    test06();
//    test07();
//    test08();
    // test09();

    return  0;

}


