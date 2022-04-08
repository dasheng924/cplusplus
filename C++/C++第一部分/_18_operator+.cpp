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

    //成员函数重载+
    Complex operator+(Complex &p) const;


    friend Complex operator+(Complex &p1,Complex &p2);
  

private:
    int m_A;
    int m_B;
};

Complex Complex::operator+(Complex &p) const
{
    Complex tmp;
    tmp.m_A = this->m_A + p.m_A ;
    tmp.m_B = this->m_B + p.m_B;
    return tmp ;//返回局部对象，会调用拷贝构造
}


Complex operator+(Complex &p1,Complex &p2)
{
    Complex tmp;
    tmp.m_A = p1.m_A + p2.m_A ;
    tmp.m_B = p1.m_B + p2.m_B;
    return tmp ;
}





int  main()
{
    Complex p1(1,2);
    Complex p2(2,3);

    Complex tmp = p1+p2 ;  //p1.operator+(p2)
    tmp.show();

    return 0 ;
}