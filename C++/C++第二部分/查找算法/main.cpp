#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

//1.查找基本数据类型
void test01()
{
    vector<int> v;
    for(int i = 0;i<10;++i)
        v.push_back(i) ;


    auto it = find(v.begin(),v.end(),3) ;
    if(it != v.end())
    {
        cout<<"find ok,value:"<<*it<<endl;
    }
    else
        cout<<"find fail!"<<endl;
}

//查找自定义类型

class Person
{
public:
    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    bool operator==(const Person &p)
    {
        if(this->m_name== p.m_name || this->m_age== p.m_age)
            return true;
        return false;
    }
    int m_age;
    string m_name;
};

void test02()
{
    vector<Person>v;
    Person p1("aaa",1);
    Person p2("bbb",2);
    Person p3("ccc",3);
    Person p4("ddd",4) ;

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    auto it = find(v.begin(),v.end(),p2);
    if(it != v.end())
    {
        cout<<"find ok,value:"<<it->m_name<<"    "<<it->m_age<<endl;
    }
    else
        cout<<"find fail!"<<endl;

}

//查找Person*
//1 public binary_function<Person*,Person*,bool>
class myCompare: public binary_function<Person*,Person*,bool> //参数，返回值
{
public:
    bool operator()(Person *p1,Person *p2)const //2. const
    {
        if(p1->m_name== p2->m_name || p1->m_age==p2->m_age)
            return true;
        return false;
    }
};
void test03()
{
    vector<Person*>v;
    Person p1("aaa",1);
    Person p2("bbb",2);
    Person p3("ccc",3);
    Person p4("ddd",4) ;

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    //查找p2一样的
    //find（）    可以直接对比两个地址，达不到对比姓名和年龄的对比，用find_if

    Person  * pp = new Person("bbb",2);
    auto it = find_if(v.begin(),v.end(),bind2nd(myCompare(),pp)); //3. bind2nd()

    if(it != v.end())
    {
        cout<<"find ok,value:"<<(*it)->m_name<<"    "<<(*it)->m_age<<endl;
    }
    else
        cout<<"find fail!"<<endl;

}

//查找重复连续的数，返回第一个的迭代器

void test04()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    v.push_back(9);

    vector<int>::iterator it = adjacent_find(v.begin(),v.end()) ;
    cout<<*it<<endl;
}


class myChoose
{
public:
    bool operator()(int v1)
    {
        return  v1>8;
    }
};

void test05()
{
    vector<int> v;
    for(int i = 0;i<10;++i)
    {
        v.push_back(i) ;
    }

    v.push_back(4);
    v.push_back(4);

    bool ret = binary_search(v.begin(),v.end(),4) ;
    if(ret)
        cout<<"find ok!"<<endl;
    else
        cout<<"find fail!"<<endl;

    cout<<"4出现的次数"<<count(v.begin(),v.end(),4) <<endl; //count()按照值来查询

    cout<<"大于8的数字个数"<<count_if(v.begin(),v.end(),myChoose()) ;


}


int main() {
//    test01();
//    test02();
//    test03();
//    test04();
    test05();


    return 0;
}


/*

auto it = find(v.begin(),v.end(),3) ;
auto it = find(v.begin(),v.end(),p2); //重载 operator==
auto it = find_if(v.begin(),v.end(),bind2nd(myCompare(),pp)); //条件查找，返回为true的情况
    //1 public binary_function<Person*,Person*,bool>
    //2 const
    //3. bind2nd()

 vector<int>::iterator it = adjacent_find(v.begin(),v.end()) ; // 查找相邻重复元素

  bool ret = binary_search(v.begin(),v.end(),4) ;


 cout<<"4出现的次数"<<count(v.begin(),v.end(),4) <<endl; //count()按照值来查询

    cout<<"大于8的数字个数"<<count_if(v.begin(),v.end(),myChoose()) ;








*/