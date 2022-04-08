#include <iostream>
#include <algorithm>
#include <random>
#include <vector>


using namespace std;


/*
	merge算法 容器元素合并，并存储到另一容器中
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
*/
void test01()
{
    vector<int> v1,v2 ;
    for(int i = 0;i<10;++i)
    {
        v1.push_back(i) ;
        v2.push_back(i+1) ;
    }

    vector<int>vTar;
    vTar.resize(v1.size() + v2.size() );
    vector<int>::iterator it = merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTar.begin());
    cout<<"查看返回的首个迭代器"<<*it<<endl;
    for_each(vTar.begin(),vTar.end(),[](int v){cout<<v<<" ";}) ;
    cout<<endl;

    //对vTar 进行反转和洗牌

    //反转
    //reverse
    reverse(vTar.begin(),vTar.end()) ;
    for_each(vTar.begin(),vTar.end(),[](int v){cout<<v<<" ";}) ;
    cout<<endl;

    //洗牌
    // std::mt19937(std::random_device()())
    shuffle(vTar.begin(),vTar.end(), std::mt19937(std::random_device()())) ;
    for_each(vTar.begin(),vTar.end(),[](int v){cout<<v<<" ";}) ;
    cout<<endl;

    std::shuffle(vTar.begin(),vTar.end(),std::mt19937(std::random_device()()));


}

void test02()
{
    //random_device 类定义的函数对象可以生成用来作为种子的随机的无符号整数值。

    auto ret = mt19937 (random_device()()) ;
    cout<<ret<<endl;

/*
    random_device rd;

    mt19937 g(rd());

    shuffle(v.begin(), v.end(), g);

    取范围[n,m]的数，写法为 rand()%(m-n+1)+n




    ---
    // 随机数种子
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rand_num(seed);	 // 大随机数
	cout << rand_num() << endl;

*/

}

int main() {


//    test01() ;
    test02();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rand_num(seed);
    std::cout << "rand_num" << rand_num<<std::endl;

    std::cout << "std::random_device="<<std::random_device()() << std::endl;




    return 0;
}
