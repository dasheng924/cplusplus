#include <iostream>
#include <map>

using namespace std;

//map 的插入方式
void test01()
{
    map<int,int>  m;
    //方法1
    m.insert(pair<int,int>(10,1));
    //方法2
    m.insert(make_pair(100,1));
    //方法3
    m.insert(map<int,int>::value_type(2,20));
    //方法4 ,不推荐，知道key值访问的时候比较方便
    m[4] = 40;

    for(auto &i:m)
    {
        cout<<"key:"<<i.first<<"\tvalue:"<<i.second<<endl;
    }
}

//map 删除的操作
void test02()
{
    map<int,int> m;
    m.insert(make_pair(10,2));
    m.insert(make_pair(1,3));

    m.erase(10);//删除容器中key为keyElem的对组
    for(auto &i:m)
    {
        cout<<"key:"<<i.first<<"\tvalue:"<<i.second<<endl;
    }

}

//map 的查找
void test03()
{
    /*
    find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
    count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
    lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    */

    map<int,int> m;
    m.insert(make_pair(10,2));
    m.insert(make_pair(1,3));

    auto it = m.find(1);
    if(it != m.end())
        cout<<"find ok,value:"<<it->second<<endl;
    else
        cout<<"not find!"<<endl;

    cout<<m.count(1)<<endl;

    pair<map<int,int>::iterator,map<int,int>::iterator> itt = m.equal_range(1) ;
    if(itt.first != m.end())
    {
        cout<<"lower_bound的key值为"<<itt.first->first<<"\tvalue值为"<<itt.first->second<<endl;
    }
    if(itt.second != m.end())
    {
        cout<<"lower_bound的key值为"<<itt.second->first<<"\tvalue值为"<<itt.second->second<<endl;
    }

}
//map 排序
class MySort
{
public:
    bool operator()(int v1,int v2)const
    {
        return v1>v2;
    }
};
//  从大到小排序
void test04()
{
    map<int,int,MySort> m;
    m.insert(make_pair(10,2));
    m.insert(make_pair(1,3));
    m.insert(make_pair(3,8));

    for(auto & i:m)
    {
        cout<<i.first<<" ";
    }
    cout<<endl;


}


//multimap 的find
void test05()
{

    //是根据key值进行排序的，如果知道同一个key的value出现的次数，就可以计算出同一个key值value出现的次数
    multimap<int,int> m;
    m.insert(make_pair(1,2));
    m.insert(make_pair(1,3));
    m.insert(make_pair(2,4));

    multimap<int,int>::iterator  it;
    it = m.find(1);

    cout<<"count:"<<m.count(1) <<endl;

    cout<<(*it).second<<endl;
    it++;
    cout<<(*it).second<<endl;
    it++;
    cout<<(*it).second<<endl;


}


int main() {
//    test01();
//    test02();
//    test03();
//    test04();
    test05();



    return 0;
}
