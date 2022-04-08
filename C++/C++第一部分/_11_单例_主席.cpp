#include <iostream>
#include <string>

using namespace std;

class ChairMan
{

//1.构造和拷贝构造私有化,防止在类外进行创建实例
private:
ChairMan(string name,int age):m_name(name),m_age(age){}
ChairMan(const ChairMan&p){m_name = p.m_name;m_age = p.m_age;}

//2.私有化一个静态对象指针
static ChairMan * singleMan;

public:
//3.提供一个接口进行访问
static ChairMan* getInstance();

private:
    string m_name;
    int m_age;
};

//2.类外初始化 静态成员变量
ChairMan * ChairMan::singleMan = new ChairMan("alex",24);

ChairMan* ChairMan::getInstance(){return singleMan ;}




int main(void)
{
    ChairMan * ch1 = ChairMan::getInstance();
    cout<<"ChairMan name:"<<ch1->m_name<<"\tage:"<<ch1->m_age<<endl;

    


    return 0 ;
}