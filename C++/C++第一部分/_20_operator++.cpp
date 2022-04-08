#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(){m_count = 0;}
 
    Complex& operator++() ;
    Complex operator++(int);

    Complex& operator--();
    Complex operator--(int);

   // friend Complex& operator++(Complex &p1);
    //friend Complex operator++(Complex &p1,int);

    friend ostream& operator<<(ostream & out,Complex &p1);

private:
    int m_count;
};

Complex& Complex::operator++() //++a
{
    this->m_count++;
    return *this;
}

Complex Complex::operator++(int) //a++,如果返回自身的话，临时局部变量会销毁，没有什么意义
{
    Complex tmp(*this);
    this->m_count++;
    return tmp;
}

//前置的运算的效率会高一点，少创建一个临时对象

Complex& Complex::operator--()
{
    this->m_count--;
    return *this;
}

Complex Complex::operator--(int)
{
    Complex tmp(*this);
    this->m_count-- ;
    return tmp;
}

#if 0
Complex& operator++(Complex &p1)
{
    p1.m_count++;
    return p1;
}

Complex operator++(Complex &p1,int)
{
    Complex tmp(p1);
    p1.m_count++;
    return tmp;
}

#endif

ostream& operator<<(ostream & out,Complex &p1)
{
    out<<p1.m_count;
    return out;
}
int main(void)
{

    Complex c;
    c++;
    ++c;
    --c;
    

    cout<<c<<endl;

    return 0;
}