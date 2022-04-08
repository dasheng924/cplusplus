/*
构造函数的分类
    有参构造
    无参构造

    普通的构造函数
    拷贝构造函数
        》》》拷贝构造函数调用时机
        1.已有对象初始化一个新的对象
        2.值传递的方式做函数的参数
        2.值传递的方式返回局部对象
*/

#include <iostream>
using std::cout;
using std::endl;


class Person
{
private:
    int m_age;
public:
    Person();//无参构造
    Person(int age);//有参构造
    Person(const Person& p);//拷贝构造
    inline void PrintAge(){cout<<"age = "<<m_age<<endl;}
};


Person::Person()
{
    cout<<"无参构造"<<endl ;
    m_age = 0 ;
}

Person::Person(int age)
{
    m_age = age ;
    cout<<"有参构造"<<endl ;
}

Person::Person(const Person &p)
{
    m_age = p.m_age;
    cout<<"拷贝构造"<<endl; 
}


int main(void)
{

#if 0
    //Person();//无参构造

    Person p;
    p.PrintAge();

#endif

#if 0
    //Person(int age);//有参构造
    Person p(100);
    p.PrintAge();



#endif

#if 0
    //Person(const Person& p);//拷贝构造

    Person p1(200);
    Person p2(p1);
    p2.PrintAge();

    Person p3 = Person(300);
    p3.PrintAge();

    Person p4(Person(400));
    p4.PrintAge() ;

    Person p5 = 100; //== 隐式转换
    p5.PrintAge();

    Person p6 = p5;
    p6.PrintAge();


#endif

/*
陈璐：2021-05-11：请将辞职信纸质版(员工本人黑色签字笔手写签字)递交/邮寄至：
江苏省南京市雨花台区花神大道98号东久创新中心一号楼5层一站式服务中心，收件人：陈璐，电话：025-58512816)，
辞职信请使用系统中的模板且离职日期应与系统中离职日期一致。
*/
    




//匿名对象

//Person（100）;//会在这行代码运行完毕后，自动销毁，

Person p7 = Person(200) ; //不会立即销毁
p7.PrintAge() ;


 //Person(p7) ; //这样调用拷贝构造的匿名对象，是错误的，只可做右值

Person p8 = Person(p7) ;
p8.PrintAge();



    return 0;
}



