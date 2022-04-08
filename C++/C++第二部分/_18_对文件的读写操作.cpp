#include <iostream>
#include <fstream>

using namespace std;

//写文件
void test01()
{
    ofstream ofs("./test.txt",ios::out | ios::trunc);

    //后期指定打开方式
    ofstream ofs1;
    ofs1.open("./test.txt",ios::out | ios::trunc) ;
    //判断是否打开
    if(!ofs1.is_open())
    {
        cout<<"open file fail!"<<endl ;
    }
    ofs1<<"name:Alex"<<endl;
    ofs1<<"age:23"<<endl;

    ofs1.close() ;

}

void test02()
{
    ifstream ifs;
    ifs.open("./test.txt",ios::in) ;
    if(!ifs.is_open())
    {
        cout<<"打开失败!"<<endl ;
    }
#if 0 
    //1.
    char buf[1024] ;
    while(ifs>>buf) //按行读取,直到读不到数据，退出循环
    {
        cout<<buf<<endl ;
    }
#endif

#if 0
    //2.
    char buf[1024];
    while(!ifs.eof())
    {
        ifs.getline(buf,sizeof(buf));
        cout<<buf<<endl;
    }
 #endif

 #if 1
    char ch ;
    while((ch=ifs.get()) != EOF)
    {
        cout<<ch;
    }


 #endif   

  

}

int main()
{
    test01();
    test02();

    return 0;
}