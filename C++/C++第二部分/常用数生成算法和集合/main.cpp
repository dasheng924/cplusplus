#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <set>

using namespace std;

void test01()
{
    vector<int>v;

    for(int i = 0;i<=100;i++)
    {
        v.push_back(i) ;
    }

    auto ret = accumulate(v.begin(),v.end(),0) ; //第三个参数为起始值
    cout<<ret<<endl;

    fill(v.begin(),v.end(),100) ;
    for(auto &i:v)
        cout<<i<<" ";
    cout<<endl;

}


/*
	set_intersection算法 求两个set集合的交集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
*/
void test02()
{

    vector<int>v1,v2 ;
    for(int i = 0;i<10;i++)
    {
        v1.push_back(i) ;
        v2.push_back(i+1) ;
    }

    copy(v1.begin(),v1.end(),ostream_iterator<int>(cout," ")) ;
    cout<<endl;
    copy(v2.begin(),v2.end(),ostream_iterator<int>(cout," ")) ;
    cout<<endl;

    vector<int> vTar;
    vTar.resize(min(v1.size(),v2.size())) ;

    auto it = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTar.begin()) ;
    copy(vTar.begin(),it,ostream_iterator<int>(cout," ")) ;

}



/*
	set_union算法 求两个set集合的并集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
*/
void test03()
{
    vector<int>v1,v2 ;
    for(int i = 0;i<10;i++)
    {
        v1.push_back(i) ;
        v2.push_back(i+1) ;
    }

    copy(v1.begin(),v1.end(),ostream_iterator<int>(cout," ")) ;
    cout<<endl;
    copy(v2.begin(),v2.end(),ostream_iterator<int>(cout," ")) ;
    cout<<endl;

    vector<int> vTar;
    vTar.resize(v1.size()+v2.size()) ;

    auto it = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),vTar.begin()) ;
    copy(vTar.begin(),it,ostream_iterator<int>(cout," ")) ;

}

/*
	set_difference算法 求两个set集合的差集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
*/
void test04()
{

    vector<int>v1,v2 ;
    for(int i = 0;i<10;i++)
    {
        v1.push_back(i) ;
        v2.push_back(i+1) ;
    }

    copy(v1.begin(),v1.end(),ostream_iterator<int>(cout," ")) ;
    cout<<endl;
    copy(v2.begin(),v2.end(),ostream_iterator<int>(cout," ")) ;
    cout<<endl;

    vector<int> vTar;
    vTar.resize(max(v1.size() , v2.size())) ;

    //注意相差时候的顺序
    auto it = set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),vTar.begin()) ;
    copy(vTar.begin(),it,ostream_iterator<int>(cout," ")) ;

}

int main() {
//    test01();

//    test02();

//    test03();

    test04();




    return 0;
}
