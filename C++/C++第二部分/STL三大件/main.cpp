#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace  std;
void show(int v)
{
    cout<<v<<endl;
}
class Person
{
public:
    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age ;
    }
    string m_name;
    int m_age;
};

//简单数据类型的遍历
void test01()
{
    vector<int> v;
    v.push_back(13);
    v.push_back(18);
    v.push_back(30);
    v.push_back(23);
#if 0
    //方法1
    vector<int>::iterator  itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

    while(itBegin != itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
#endif

#if 0
    //方法2
    for(vector<int>::iterator it = v.begin();it != v.end();++it)
    {
        cout<<*it<<endl;
    }
#endif

#if 1
    //方法3
    for_each(v.begin(),v.end(),show) ;
#endif
}

//存放自定义类型
void test02()
{
    vector<Person> v;
    Person p1("鲁班",2);
    Person p2("后裔",23);
    Person p3("女娲",99);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for(vector<Person>::iterator it = v.begin();it != v.end();++it)
    {
        cout<<"name:"<<(*it).m_name<<"\tage:"<<it->m_age<<endl;
    }
}

// 存放自定义类型指针
void test03()
{

    vector<Person*> v;
    Person p1("鲁班",2);
    Person p2("后裔",23);
    Person p3("女娲",99);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    for(vector<Person*>::iterator it = v.begin();it != v.end();++it)
    {
        cout<<"name:"<<(*it)->m_name<<"\tage:"<<(**it).m_age<<endl;
    }
}

//大容器vector里面套小的vector
void test04()
{
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for(int i = 0;i< 6;++i)
    {
        v1.push_back(i+10);
        v2.push_back(i+100);
        v3.push_back(i+23);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(vector<vector<int>>::iterator it = v.begin();it != v.end();++it)
    {
        for(vector<int>::iterator it2 = (*it).begin();it2 != (*it).end();++it2)
        {
            cout<<*it2<<"\t";
        }
        cout<<endl;
    }


}

int main()
{
//    test01();
//    test02();
//    test03();
      test04();

    return  0;
}