#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class MyPrint
{
public:
    void operator()(const string& str)
    {
        cout<<str<<endl;
        count ++;  //拥有自己的状态
    }
    int count = 0;
};


void test01()
{
    MyPrint m;
    m("alex"); //仿函数（函数对象）
    m("ddd");
    m("xxx");

    cout<<"调用的次数:"<<m.count<<endl;
    MyPrint()("Lucy") ;//MyPrint() 匿名对象
}



//函数对象做函数参数
void Print(MyPrint myPrint,const string& name)
{
    myPrint(name);
}

void test02()
{
    MyPrint m;
    Print(m,"qqq");
}


class Mygreater
{
public:
    bool operator()(int v)
    {
        return v > 20;
    }
};
//谓词
void test03()
{

    //一元谓词 返回值为bool的函数重载或者函数对象
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);


    for_each(v.begin(),v.end(),[](int v){cout<<v<<" ";}) ; //匿名函数
    //排序
    sort(v.begin(),v.end()) ;//默认从小到大
    cout<<"\n--------------"<<endl;
    for_each(v.begin(),v.end(),[](int v){cout<<v<<" ";}) ; //匿名函数

    //从小到大的排序，利用函数对象,二元谓词的利用
    sort(v.begin(),v.end(),greater<int>());
    cout<<"\n--------------"<<endl;
    for_each(v.begin(),v.end(),[](int v){cout<<v<<" ";}) ; //匿名函数



    for_each(v.begin(),v.end(),[](int v){cout<<v<<" ";}) ; //匿名函数
    //一元谓词的利用，找出这个vector中大于15 的第一个数
    vector<int>::iterator  it = find_if(v.begin(),v.end(),Mygreater());
    cout<<"\n大于20的第一个数为"<<*it<<endl;



    int value {5};
    auto iter1 = find_if(begin(v),end(v),[value](int n) { return n > value; });

    if(iter1 != std::end(v))
        std::cout << *iter1 << " was found greater than " << value << ".\n";










}

//内建函数对象
void test04()
{
    //取反的仿函数
    negate<int>n;
    cout<<n(10)<<endl;

    //加法的仿函数
    cout<<plus<int>()(10,20)<<endl;
    //减法的仿函数
    cout<<minus<int>()(10,2)<<endl;

    cout<<multiplies<int>()(10,2)<<endl;







}


int main() {
//    test01();
//    test02();
    test03();
//    test04();


    return 0;
}
