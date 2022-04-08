#include <iostream>

using namespace std;

class Person{

public:
    Person(int var1):num1(var1){}
    Person(const Person &obj);
    inline void show();
private:
    int num1 ;
    const int num2 = 10;//非静态数据成员的类内初始化是 C++11 扩展
    //最好还是用 初始化列表进行初始化
};

inline void Person::show()
{
    cout<<"num1="<<num1<<"\tnum2="<<num2<<endl;
}


int main(void)
{

    Person p(1);
    p.show();

    return 0;
}