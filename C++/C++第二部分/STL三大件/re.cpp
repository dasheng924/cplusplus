#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;


void print(int val)
{
    cout<<val<<" ";
}
class Test
{
public:
    void operator()(int val)
    {
        cout<<val<<" ";
    }
};

class Person
{
public:
    Person(string str):name(str){}
    string name;
};
void test01()
{
    vector<int> v;
    for(int i = 0;i<10;++i)
    {
        v.push_back(i+1);
    }

    v.insert(v.begin(),111);

    //1
    vector<int>::iterator it =v.begin();
   
    while (it != v.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    //2
    for(auto it=v.begin();it != v.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //3
    for_each(v.begin(),v.end(),[](int val){cout<<val<<" ";});
    cout<<endl;
    //4
    for_each(v.begin(),v.end(),print);
    cout<<endl;
    //5
    using TYPE=void(*)(int);
    TYPE t=print;
    for_each(v.begin(),v.end(),t);
    cout<<endl;
    //6
    for_each(v.begin(),v.end(),Test());
    cout<<endl;

    function<void(int)> f1=t;
    function<void(int)> f2=Test(); //可调用对象包装器--》包装类的时候，里面要有operator() 的仿函数

     //7
    for_each(v.begin(),v.end(),f1);
    cout<<endl;
     //8
    for_each(v.begin(),v.end(),f2);
    cout<<endl;

}


void print_P(const Person &p)
{
    cout<<p.name<<endl;
}
void test02()
{
    vector<Person> v;
    Person p1("alex");
    Person p2("Lucy");
    Person p3("good");

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

   for(auto it=v.begin();it !=v.end();++it)
   {
       cout<<(*it).name<<endl;
   }

   for_each(v.begin(),v.end(),[](const Person &p){
       cout<<p.name<<endl;
   });

   for_each(v.begin(),v.end(),print_P);

}

void test03()
{

    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    
    for(int i = 0;i<10;++i)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(auto it = v.begin();it != v.end();++it)
    {
       for(auto itt = (*it).begin();itt != (*it).end();++itt)
            cout<<*itt<<" ";
        cout<<endl;
    }


}


int main()
{
    // test01();

    // test02();

    test03();


    return 0;
}