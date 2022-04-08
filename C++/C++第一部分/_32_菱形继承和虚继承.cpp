#include <iostream>
//菱形继承的问题：会把最基类的数据在次基类中拷贝多份，导致最后的派生类中有多分同样的数据
//菱形继承：造成派生类中的数据冗余问题和命名冲突问题

//解决这个问题就需要虚继承的出现：只保留一份副本，这个副本被基类进行共享







using namespace std;
class Animal    
{
public:
    Animal()
    {
        m_A = 10;
        cout<<"Animal cons"<<endl ;
    }
    int m_A;
    ~Animal(){cout<<"Animal desc"<<endl ;}
};

class Sheep:virtual public Animal
{
public:
    Sheep(){cout<<"Sheep cons"<<endl ;}
    ~Sheep(){cout<<"Sheep desc"<<endl;}

};

class Tuo:virtual public Animal
{
public:
    Tuo(){cout<<"Tuo cons"<<endl ;}
    ~Tuo(){cout<<"Tuo desc"<<endl ;}

};
class SheepTuo:public Tuo,public Sheep //构造的顺序与这个初始化的顺序是相关的
{
public:
    SheepTuo(){cout<<"SheepTuo cons"<<endl ;}
    ~SheepTuo(){cout<<"SheepTuo desc"<<endl ;}
};

int main()
{
    
    SheepTuo st;
    st.Tuo::m_A = 30 ;
    st.Sheep::m_A = 20;
    //  m_A 只有一份了，m_A 最终结果为20
    
    cout<<"m_A = "<<st.m_A<<endl ; 
    
    //在这个st的内存布局图里面，有Sheep 的虚基类指针，有Tuo的虚基类指针，有m_A ，
    cout<<"sizeof(st) = "<<sizeof(st)<<endl;
    

#if 0
    cout<<"sizeof(virtual Sheep) = "<<sizeof(Sheep)<<endl ; //sizeof(virtual Sheep) = 16

    cout<<"sizeof(virtual Sheep) = "<<sizeof(Sheep)<<endl ; //sizeof(virtual Sheep) = 16
#endif

#if 0
    cout<<"sizeof(Sheep) = "<<sizeof(Sheep)<<endl ; //sizeof(Sheep) = 4

    cout<<"sizeof(Sheep) = "<<sizeof(Sheep)<<endl ; //sizeof(Sheep) = 4
#endif



    return 0;
}

/*
Animal cons
Sheep cons
Tuo cons
SheepTuo cons
m_A = 10
sizeof(st) = 24
SheepTuo desc
Tuo desc
Sheep desc
Animal desc



*/

/*
//菱形继承的时候，次基类也必须写初始化语句，但是不会调用，最终的调用在最下面的派生类中
class BigBase{
public:
	BigBase(int x){mParam = x;}
	void func(){cout << "BigBase::func" << endl;}
public:
	int mParam;
};
class Base1 : virtual public BigBase{
public:
	Base1() :BigBase(10){} //不调用BigBase构造
};
class Base2 : virtual public BigBase{
public:
	Base2() :BigBase(10){} //不调用BigBase构造
};

class Derived : public Base1, public Base2{
public:
	Derived() :BigBase(10){} //调用BigBase构造
};
//每一次继承子类中都必须书写初始化语句
int main(){
	Derived derived;
	return EXIT_SUCCESS;
}
*/