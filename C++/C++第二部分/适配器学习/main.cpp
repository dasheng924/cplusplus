#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;


//2。继承类，二元适配器 绑定适配器
class Print: public binary_function<int,int,void>
{
public:
    void operator()(int v,int start)const //3。加const
    {
        cout<<" v = "<<v<<" start = "<<start<<" v+start "<<v+start<<endl;
        //cout<<v+start<<endl;
    }

};
void test01()
{
    vector<int> v;
    v.reserve(10);
    for(int i = 0;i<10;++i)
    {
        v.push_back(i);
    }

    int num;
    cout<<"请输入你要每一项加的数："<<endl;
    cin>>num;

    //输出加起始值
    //1.bind2nd() 绑定恒定值
    //二元适配器
    for_each(v.begin(),v.end(),bind2nd(Print(),num)) ;
    //for_each(v.begin(),v.end(),bind1st(Print(),num)) ;
} ;

//一元适配器 取反适配器
//先写一个查找大于5的数，然后通过取反适配器找到小于5的数

//2.
class MyGreater: public unary_function<int,bool>
{
public:
    bool operator()(int v) const //3
    {
        return v>5;
    }
};
void test02()
{
    vector<int> v;
    v.reserve(10);
for(int i = 0;i<10;i++)
    {
        v.push_back(i) ;
    }

    auto pos = find_if(v.begin(),v.end(),MyGreater()) ;
    if(pos != v.end())
    {
        cout<<"> 5 find ok,value = "<<*pos<<endl;
    } else{cout<<"find fail!"<<endl;}

    //取反适配器找到小于5的数
    //1.
    auto pos1 = find_if(v.begin(),v.end(),not1(MyGreater())) ;
    if(pos1 != v.end())
    {
        cout<<"< 5 find ok,value = "<<*pos1<<endl;
    } else{cout<<"find fail!"<<endl;}


    //not1(bind2nd(greater<int>(),5))) 先把大于的内建函数对象和5绑定，在用取反适配器进行取反
    auto pos3 = find_if(v.begin(),v.end(),not1(bind2nd(greater<int>(),5))) ;
    if(pos3 != v.end())
    {
        cout<<"< 5 find ok,value = "<<*pos3<<endl;
    } else{cout<<"find fail!"<<endl;}
}



void showow(int v,int start)
{
    cout<<v+start<<endl;
}
//函数指针适配器
//将函数指针适配为函数对象
//ptr_fun(函数)
void test03()
{
    vector<int> v;
    for(int i = 0;i<5;++i)
    {
        v.push_back(i) ;
    }

     // for_each(v.begin(),v.end(),show) ; //直接使用回调函数

     for_each(begin(v),end(v),bind2nd(ptr_fun(showow),100) );

}


//成员函数适配器
class Person
{
public:

    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void show()
    {
        cout<<"name "<<this->m_name<<"  age "<<this->m_age<<endl;
    }
    int m_age;
    string m_name;

    void add()
    {
        this->m_age+=100 ;
    }
};
void test04()
{
    vector<Person> v;
    Person p1("aaa",1);
    Person p2("bbb",2);
    Person p3("ccc",3);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for_each(v.begin(),v.end(),mem_fun_ref(&Person::show)) ;
    for_each(v.begin(),v.end(),mem_fun_ref(&Person::add)) ;
    for_each(v.begin(),v.end(),mem_fun_ref(&Person::show)) ;
}

int main() {

//    test01();
//    test02();
//    test03();
    test04();

    return 0;
}


bind2nd

ptr_fun()//函数指针适配器

mem_fun_ref() //成员函数适配器