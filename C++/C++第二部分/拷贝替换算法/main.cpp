#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>


using namespace std;


void test01()
{

    vector<int> v1;
    for(int i = 0;i<10;++i)
        v1.push_back(i) ;

    vector<int> v2;
    v2.resize(v1.size()) ;

    copy(v1.begin(),v1.end(),v2.begin()) ;

    for_each(v2.begin(),v2.end(),[](int v){cout<<v<<" " ;} ) ;
    cout<<endl;

    //把数据拷贝到输出流中
    copy(v2.begin(),v2.end(),ostream_iterator<int>(cout," ")) ;
   

    cout<<endl ;
}


class myChoose
{
public:
    bool operator()(int v)
    {
        return v > 3;
    }
};

void test02()
{
    //replace
    vector<int> v;
    for(int i = 0;i<6;++i)
    {
        v.push_back(i) ;
    }

    replace(v.begin(),v.end(),2,100) ;
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," ")) ;
    cout<<endl;

    //有条件的替换,用自定义的函数对象
    replace_if(v.begin(),v.end(),myChoose(),1000);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," ")) ;
    cout<<endl;

    //用匿名函数
    int value{1000};
    replace_if(v.begin(),v.end(),[value](int v){return v>=value ;},99);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," ")) ;
    cout<<endl;

    //用系统内建的函数对象
    replace_if(v.begin(),v.end(),bind2nd(greater_equal<int>(),99),111);

    

}

//swap
void test03()
{
    list<int> v1,v2 ;
    for(int i = 0;i<10;i++)
    {
        v1.push_front(i) ;
        v2.push_back(i+1) ;
    }

    for(auto i:v1)
        cout<<i<<" ";
    cout<<endl;

    for(auto i:v2)
        cout<<i<<" ";
    cout<<endl;

    swap(v1,v2) ;


    for(auto i:v1)
        cout<<i<<" ";
    cout<<endl;

    for(auto i:v2)
        cout<<i<<" ";
    cout<<endl;





}

int main() {
//    test01();
//    test02() ;
    test03();



    return 0;
}
