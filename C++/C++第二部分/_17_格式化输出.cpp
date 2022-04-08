#include <iostream>
#include <iomanip>

using namespace std;

/*
1）使用控制符的方法；
2）使用流对象的有关成员函数。
*/
void test01()
{
    int num = 10;
    cout.width(10);
    cout.fill('*');
    cout.setf(ios::left);
    cout.unsetf(ios::dec);
    cout.setf(ios::hex|ios::showbase);
    cout.unsetf(ios::hex) ;
    cout.setf(ios::showpos);
    cout<<num<<endl ;

}

void test02()
{
    int num = 11;
    cout<<setw(8)<<setfill('-')<<hex<<setiosflags(ios::uppercase)<<num<<endl;

}





int main()
{   

    //test01();
    test02();


    return 0;
}