#include <iostream>
#include <string>

using namespace std;

class Building
{
    //1.friend关键字只出现在声明处
    friend void GoodGay(Building * building);//2.不是类的成员函数，不带this指针
public: //注意默认的访问权限
    Building()
    {
        livingRoom = "客厅";
        badRoom = "卧室";
    }

public:
    string livingRoom;
private:
    string badRoom;

};

//3.友元函数可以访问类的私有属性
void GoodGay(Building * building)
{
    cout<<"好基友,正在访问"<<building->livingRoom<<endl;
    cout<<"好基友,正在访问"<<building->badRoom<<endl; 
}

void test01()
{
   Building * b = new Building;  
    GoodGay(b);
}

int main(void)
{
    test01();
}


//4。友元关系不能被继承，传递，单向的关系
