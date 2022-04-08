#include <iostream>

using namespace std;

/*
cin.get() //缓冲区中读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串，cin.get(buf,len) ,不读取换行
cin.getline() //cin.getline(buf,len) ;读取一行，包括换行，不过舍弃换行符
cin.ignore() // 不输入参数，表示忽略开头的一个字符，cin.ignore(2
cin.peek() ////偷看一下缓冲区的第一个字符，不拿出来
cin.putback() //cin.putback(ch); 把ch字符放回缓冲区

*/
void test01()
{
    char ch = cin.get();//获取一个字符
    cout<<ch; //

    ch = cin.get();//获取一个字符
    cout<<ch; //

    ch = cin.get();//获取一个字符 ,可以获取到末尾的换行
    cout<<ch ;
    if(ch == '\n')
    {
        cout<<"末尾你输入的是换行"<<endl ;
    }
}

void test02()
{
    //cin.get(两个参数) //可以读字符串
    char buf[1024] = {0};
    cin.get(buf,1024) ; //不读 末尾的换行符
    cout<<buf<<endl ;

    char ch = cin.get();
    if(ch == '\n')
        cout<<"读取字符串的时候没有把末尾的换行读到"<<endl ;
}


void test03()
{

    char buf[1024] = {0} ;
    cin.getline(buf,1024) ;  //把换行读取，并且扔掉
    cout<<buf<<endl ;
}

void test04()
{
#if 0
    cin.ignore() ; //不输入参数，默认忽略一个字符
    char ch = cin.get();
    cout<<ch<<endl ;
#endif

    cin.ignore(2);//忽略前两个字符
    char ch = cin.get();
    cout<<ch<<endl ;
}

void test05()
{
    cin.peek(); //偷看一下缓冲区的第一个字符，不拿出来
    char ch = cin.get() ;
    cout<<ch<<endl ;
}

void test06()
{
    char ch = cin.get();
    cin.putback(ch);

    char buf[1024] = {0};
    cin.getline(buf,1024);
    cout<<buf<<endl ;

}

void test07()
{
    char ch ;
    cin.get(ch);
    cout<<ch<<endl ;


}


int main()
{
    //test01();
    //test02();
    //test03() ;
    //test04();
    //test05() ;
    //test06();
    test07();


    return 0;
}