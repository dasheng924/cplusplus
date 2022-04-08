#include <iostream>

using namespace std;
class BaseCal
{
public:
    //virtual int result(){return 0;}
    virtual int result()=0;  //纯虚函数
    
    void setVal(int a,int b)
    {
        this->m_a = a;
        this->m_b = b;
    }
    int m_a;
    int m_b;
};

class plusCal:public BaseCal
{
public:
    virtual int result()
    {
        return this->m_a + this->m_b ;
    }
};

class subCal:public BaseCal
{
    virtual int result()
    {
        return this->m_a - this->m_b ;
    }
};

int doCal(BaseCal * basecal)
{
    return basecal->result();
}

void testPlus()
{
    BaseCal * basecal = new plusCal;
    basecal->setVal(1,3);
    cout<<doCal(basecal)<<endl ;
}
void testSub()
{
    BaseCal * basecal = new subCal;
    basecal->setVal(1,3);
    cout<<doCal(basecal)<<endl ;
}





int main()
{
    testPlus();
    testSub();



    return 0;
}