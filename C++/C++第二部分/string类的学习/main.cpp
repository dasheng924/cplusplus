#include <iostream>
#include <string>
#include <exception>

using namespace  std;

//string 的构造
void test01()
{
    string str1;//默认构造
    string str2(str1);//拷贝构造
    string str3 = str1; //等号法

    string str4 = "help";
    string str5(10,'a');

    cout<<str4<<endl;
    cout<<str5<<endl;
}

//基本的赋值
void test02()
{
    string str1;
    str1 = "alex";

    //string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
    string str2 ;
    str2.assign("alex",2);
    cout<<str2<<endl; //al

    //string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
    string str3;
    str3.assign(str1,2);
    cout<<"str3 = "<<str3<<endl; //str3 = ex,从0开始索引
    str3.assign(str1,2,1); //str3 = e
    cout<<"str3 = "<<str3<<endl;
}

//string存取操作
void test03()
{
    /*
     * char& operator[](int n);//通过[]方式取字符
     * char& at(int n);//通过at方法获取字符
     */

    string str1 = "helcrever";
    cout<<str1[0]<<endl; //越界直接over
    try{
        cout<<str1.at(20)<<endl; //越界抛出异常
    }
    catch (out_of_range &e)
    {
        cout<<e.what()<<endl;
    }
    catch(...)
    {
        cout<<"异常"<<endl;
    }

}

//string的拼接
void test04()
{
/*
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c
*/
    string str1("我爱");
    string str2("China");
    string str3;
    str3 = str1 + str2 ;
    cout<<str3<<endl;

    str3.append("的美食！");
    cout<<str3<<endl;

}

//string的算法
void test05()
{
    string str1 = "hello" ;
    //pos 的位置从0开始
    //find
    int pos1 = str1.find('e'); //找不到返回-1
    cout<<pos1<<endl;

    //rfind
    int pos = str1.rfind('e'); //找的时候从后往前，但是输出结果还是正向的
    cout<<pos<<endl;

    //replace
    /*
     string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
     string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
     */
    string str2 = "apple";
    str2.replace(1, 2, "JJJJ") ;
    cout<<str2<<endl;

    //compare
/*
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。

    int compare(const string &s) const;//与字符串s比较
    int compare(const char *s) const;//与字符串s比较
*/

    string str3 = "apple";
    string str4 = "APPLE";

    int ret = str3.compare(str4);

    if(!ret)
    {
        cout<<"相等"<<endl ;
    }
    else
    {
        cout<<"不相等"<<endl;
    }

    //substr
    //string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

    string str5 = "12345" ;
    cout<<str5.substr(1,2)<<endl;

    string email = "dasheng5299@163.com";
    string userName = email.substr(0,email.find("@"));
    cout<<"userName = "<<userName<<endl;

    //insert

/*
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c

string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/

    string str6 = "apple" ;
    str6.insert(1,"32");
    cout<<str6<<endl;

    str6.erase(1,1) ;
    cout<<str6<<endl;

    // 转换
    /*
     //string 转 char*
string str = "itcast";
const char* cstr = str.c_str();
//char* 转 string
char* s = "itcast";
string str(s);
     */
    //string 转 char*
    string str7 = "dasheng";
    char * name = const_cast<char*>(str7.c_str());

    //char * 转string

    char * name2 = "dasheng" ;
    string NAME(name2);
    cout<< typeid(NAME).name()<<endl;

    //const char * 可以隐式类型转换为 string
    //string 不能隐式转换为char *




}

//所有的小写变大写
void test06()
{
    string str1;
    str1 = "swdSWDWwsd2";
    for(int i = 0;i<str1.size();++i)
    {
        str1[i] = toupper(str1[i]) ;
    }


    cout<<str1<<endl;

}

int main()
{
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
    test06() ;
    return 0;
}

