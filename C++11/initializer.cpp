#include <iostream>
#include <string>
#include <list>
using namespace std;

//聚合类型：数组；无基类，无虚函数，无自定义构造函数，无私有成员或者受保护非静态成员
//非聚合类型：需要提供对应的构造函数

struct Test
{
    int a;
    int b;
    string c;
};

struct Test2
{
    Test2(int a,int b,string c,string d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    int a;
    int b;
    string c;
private:
    string d;
};

struct Test22
{

    int a;
    int b;
    string c;
private:
    string d;
};
struct Test3
{
    Test22 t;
    int b;
    string c;
};

//可以接受任意多个相同类型的数据
void show(initializer_list<int> l)
{
    for(auto i:l)
    {
        cout<<i<<endl;
    }
}

template<class T>
class  TTest
{
public:
    TTest(initializer_list<T> l)//这样类的内部就 拿到了对应的数据
    {
        for(auto i:l)
        {
            m_list.push_back(i);
        }
    }
    void print()
    {
        for(auto i:m_list)
        {
            cout<<i<<endl;
        }
    }


private:
    list<T> m_list;
};


int main()
{

    int arr[]{1,23,4,56};
    Test t{1,2,"apple"};
    Test2 t2{1,2,"apple","alex"};//非聚合类型需要提供自定义构造函数

    Test3 t3{{},1,"apple"};//聚合包裹非聚合，看聚合的定义，不与里面的非聚合有关系

    show({1,23,4,100});

    cout<<"================"<<endl;
    TTest<string> tt{"apple","good","alex"};
    tt.print();

    return 0;
}
