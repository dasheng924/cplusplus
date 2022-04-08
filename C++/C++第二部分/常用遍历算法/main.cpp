#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;


//遍历打印
struct myShow1
{
    void operator()(int v)
    {
        cout<<v<<endl;
    }
};
void test01()
{
    vector<int> v;
    for(int i = 0;i< 10;++i)
    {
        v.push_back(i) ;
    }

#if 0
    //for 循环
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
#endif
#if 0
    //伪函数
    for_each(v.begin(),v.end(),[](int v){cout<<v<<endl;}) ;
#endif
#if 1
    //函数对象
    for_each(v.begin(),v.end(),myShow1()) ;
#endif

    //也可以回调函数
}

//遍历时携带信息
struct myShow2
{
    void operator()(int v)
    {
        cout<<v<<endl;
        m_count++;
    }
    int m_count;
};
void test02()
{
    vector<int> v;
    for(int i = 0;i< 10;++i)
    {
        v.push_back(i) ;
    }

    // myShow2 m 返回值为函数对象
    myShow2 m = for_each(v.begin(),v.end(),myShow2()) ; //遍历时携带信息
    cout<<"次数:"<<m.m_count<<endl;

}


 struct myShow3: public binary_function<int,int,void>
 {
    void operator()(int v1,int start)const
    {
        cout<<v1+start<<endl;
    }

 };


//绑定参数进行输出
void test03()
{
    vector<int> v;
    for(int i = 0;i< 10;++i)
    {
        v.push_back(i) ;
    }

    //for_each(v.begin(),v.end(),bind2nd(myShow3(),100)) ;

#if 0
    int num{100};
    for_each(v.begin(),v.end(),[num](int v){cout<<v+num<<endl;}) ;
#endif
}


//transfrom
/*
	transform算法 将指定容器区间元素搬运到另一容器中
	注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
	@param beg1 源容器开始迭代器
	@param end1 源容器结束迭代器
	@param beg2 目标容器开始迭代器
	@param _cakkback 回调函数或者函数对象
	@return 返回目标容器迭代器
*/


class resultVal
{
public:
    int operator()(int v)
    {
        return  v;
    }
};
void test04()
{
    vector<int> v;
    for(int i = 0;i< 10;++i)
    {
        v.push_back(i) ;
    }

    vector<int> vTar;
    vTar.resize(10);

    transform(v.begin(),v.end(),vTar.begin(),resultVal()) ;

    for(auto i:vTar)
        cout<<i<<endl;
}

//v1 + v2 -->vTar

struct sumShow
{
    int  operator()(int v1,int v2)
    {
        return v1+ v2;
    }
};
void test05()
{
    vector<int> v1,v2;
    for(int i = 0;i< 10;++i)
    {
        v1.push_back(i) ;
        v2.push_back(i) ;
    }

    vector<int>vTar;
    vTar.resize(10) ;

    //transform(v1.begin(),v1.end(),v2.begin(),vTar.begin(),sumShow()  );

    transform(v1.begin(),v1.end(),v2.begin(),vTar.begin(),[](int v1,int v2){return v1+v2;} );

    for(auto i:vTar)
        cout<<i<<endl;
}

int main() {
//    test01();
//    test02();
//    test03();

//    test04();
    test05();

    return 0;
}
