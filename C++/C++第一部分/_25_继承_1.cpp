#include <iostream>
using namespace std ;


class BasePage
{
public:
    void head(){cout<<"公共头部"<<endl ;}
    void button(){cout<<"公共底部"<<endl ;}
    void left(){cout<<"左侧列表"<<endl ;}

};

//继承：代码复用
class NewPage:public BasePage
{
public:

    void content(){cout<<"新闻直播"<<endl ;}

};

class Yl:public BasePage
{
public:
    void content(){cout<<"KPL"<<endl;}

};
int main()
{   
    Yl y1;
    y1.head();
    y1.button();
    y1.left();
    y1.content();


    return 0;
}