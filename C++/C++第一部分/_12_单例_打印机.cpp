
#include <iostream>
#include <string>

using namespace std;

class Printer
{
private:
    Printer(){m_count = 0;}
    Printer(const Printer &p){}

private:
    static Printer * singlePrinter;
    unsigned int m_count;

public:
    static Printer* getInstance(){return singlePrinter ;}
    void contents(string con){cout<<"打印 《"<<con<<"》"<<endl ;m_count++ ;}
    unsigned int getCount(void){return m_count ;}

};

Printer * Printer::singlePrinter = new Printer;

int main(void)
{
    Printer * p = Printer::getInstance();
    p->contents("申请书");
    p->contents("小说");
    p->contents("辞职");

    cout<<"打印的次数"<<p->getCount()<<endl ;


    return 0;
}