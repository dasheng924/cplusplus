#include <iostream>
#include <map>
using namespace  std;

template<typename  T>
class MyMap{
public:
    typedef map<int,T> mapType; //不能在类的外部起别名
};


template<typename T>
void showMap(T &t)
{
    for(auto i:t)
    {
        cout<<i.first<<"    "<<i.second<<endl;
    }

}

template<typename T>
class Continer
{
public:
    void show(T &t)
    {
        for(auto i:t)
        {
            cout<<i.first<<"    "<<i.second<<endl;
        }
    }
};

template<typename T>
using mmap = map<int,T>;

int main(){

    MyMap<int>::mapType m1;
    m1[1] = 2;
    m1[2] = 3;
    m1[3] = 4;

    showMap<MyMap<int>::mapType>(m1);

    MyMap<double>::mapType m2;
    m2.insert(make_pair(1,12.12));
    m2.insert(make_pair(2,23.12));
    Continer<MyMap<double>::mapType> c;
    c.show(m2);

    MyMap<string>::mapType m3;
    m3.insert(make_pair(1,"apple"));
    m3.insert(make_pair(2,"good"));

    mmap<string> m4;
    m4.insert(make_pair(1,"good"));
    m4.insert(make_pair(2,"alex"));
    showMap(m4);








    return 0;
}