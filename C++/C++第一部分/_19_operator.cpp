#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(){m_A = 0;m_B = 0;}
    Complex(int a,int b):m_A(a),m_B(b){}


    void show() const
    {
        cout<<m_A<<"\t"<<m_B<<endl; 
    }

    friend ostream& operator<<(ostream & out, Complex &p1);  
    //<< 不能用成员函数重载，因为 ostream 这个类无法进行修改，同时两个操作数的类型也不一致


  

private:
    int m_A;
    int m_B;
};

ostream & operator<<(ostream &out, Complex &p1)
{
    out<<p1.m_A<<"\t"<<p1.m_B;
    return out;
}   



int  main()
{
    Complex p1(1,2);
    
    cout<<p1<<endl;

    return 0 ;
}