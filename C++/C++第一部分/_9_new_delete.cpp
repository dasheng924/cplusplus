#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    Person(int num);
    ~Person();
};

Person::Person(/* args */)
{
    cout<<"构造函数"<<endl;
}

Person::Person(int num)
{
    cout<<num<<"有参构造"<<endl ;
}

Person::~Person()
{
    cout<<"析构函数"<<endl;
}



int main(void)
{

#if 0
    Person *p = new Person;

    delete p ;

    //在堆区，必须要指定默认构造
    Person * array = new Person[3];
    //在栈区，可以指定调用有参构造,也叫做聚合初始化
    Person  array2[3] = {Person(1),Person(2),Person(3)} ;

    delete []array;
#endif

#if 0
    void * array3 = new Person[4]; // 不要用void * 去接收
    delete []array3;
#endif

#if 0

    char * pCh = new char[10]; //字符数组 
    strcpy(pCh,"hello world");
    cout<<pCh<<endl;
    int * pInt = new int[3];
    for(int i = 0;i<3;++i)
    {
        pInt[i] = i+1;
    }

    for(int i = 0;i<3;++i)
        cout<<pInt[i]<<"\t";
    cout<<endl;

    delete []pCh;
    delete []pInt;




#endif

    return 0;
}

/*
1.new 返回的是一个指向对象的指针；malloc 返回的是void * ，在C++中需要转换

2.new 和delete配合使用；malloc和free配合使用，不能混用

3.new 会调用构造函数，delete会调用析构函数；

4.new，delete 是运算符 ；malloc和free是函数




*/