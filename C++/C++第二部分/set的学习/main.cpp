#include <iostream>
#include <set>

using namespace std;
void printSet(const set<int> &s)
{
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

#if 0


void test01()
{

    set<int> s1; //关联式容器会自动排序，从小到大
    s1.insert(10);
    s1.insert(12);
    s1.insert(9);

    printSet(s1);
    if(!s1.empty())
    {
        cout<<"set s1不为空"<<endl;
    }
    cout<<"s1 的大小"<<s1.size()<<endl;

    //erase(elem);//删除容器中值为elem的元素
    s1.erase(12);
    printSet(s1);
}



//set 的查找
void test02()
{
    /*
    find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    count(key);//查找键key的元素个数
    lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
     */

    //对于set来说，key就是value

    set<int> s1; //关联式容器会自动排序，从小到大
    s1.insert(10);
    s1.insert(12);
    s1.insert(9);

    auto it = s1.find(10); //返回值为迭代器，找不见返回end（）
    if(it != s1.end())
    {
        cout<<"找见了,值为"<<*it<<endl;
    }
    else
    {
        cout<<"找不见"<<endl;
    }
    cout<<"10 的个数"<<s1.count(10)<<endl; //计数，对于set，是0或者1

    auto it2 = s1.lower_bound(9);//返回第一个key>=keyElem元素的迭代器。
    auto it3 = s1.upper_bound(9);//返回第一个key>keyElem元素的迭代器。
    cout<<"*it2: "<<*it2<<"\t*it3: "<<*it3<<endl;

    pair<set<int>::iterator,set<int>::iterator> it4= s1.equal_range(9);//返回容器中key与keyElem相等的上下限的两个迭代器。
    
    //equal_range 的两个返回值相等于 lower_bound  upper_bound
    cout<<"first value:"<<*(it4.first)<<"\tsecondValue:"<<*(it4.second)<<endl;

    //cout<< typeid(it4).name()<<endl;



}


//set 插入的值是唯一的，不允许插入重复的值
void test03()
{
    set<int> s1;
    //pair<set<int>::iterator,bool> ret = s1.insert(1);
    auto ret = s1.insert(1);
    if(ret.second)
        cout<<"插入成功!"<<endl;
    else
        cout<<"插入失败!"<<endl;

    ret  = s1.insert(1);
    if(ret.second)
        cout<<"第二次插入成功!"<<endl;
    else
        cout<<"第二次插入失败!"<<endl;


    printSet(s1);
}


//set 的从大到小的排序
class myCompare
{
public:
    bool operator()(int v1,int v2) const
    {
        //set的排序，默认存储的时候就是从小到大的顺序
            return v1>v2;
    }
};
void test04()
{
//    set<int>s;
//    s.insert(10);
//    s.insert(1);
//    s.insert(9);
//
//    printSet(s);//已经顺序输出

    //如果要从大到小的输出,要插入之前指定好排序规则
  set<int,myCompare> s; //<>里面放的是数据类型，需要自定义一个类型
  s.insert(3);
  s.insert(8);
  s.insert(1);

  for(auto & i:s)
  {
      cout<<i<<" ";
  }
  cout<<endl;
}

#endif


class Person
{
public:
    Person(string name,int age)
    {
        this->m_name = move(name);
        this->m_age = age;
    }

    string m_name;
    int m_age;
};

class mySort
{
public:
    bool operator()(const Person &p1,const Person &p2)const
    {
        return p1.m_age  > p2.m_age;
    }
};

void test05()
{
    set<Person,mySort> s;  //自定义类型需要开始的时候就指定插入的排序规则,排序规则对于基础的数据类型是不用指定的，自定义数据类型，需要构造的时候就进行指定
    Person p1("鲁班",12);
    Person p2("女娲",99);
    Person p3("孙尚香",36);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);



    for(set<Person>::iterator it  = s.begin();it != s.end();++it)
    {
        cout<<"name: "<<it->m_name<<"\tage: "<<it->m_age<<endl;
    }



}

void test06()
{
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);

    for(auto &i:ms)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}


int main() {
    //test01();
//    test02();

//    test03();
//      test04();
//    test05();
    test06();

    
    return 0;
}
