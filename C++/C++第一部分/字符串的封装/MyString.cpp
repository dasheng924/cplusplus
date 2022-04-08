#include "MyString.h"

MyString::MyString(const char *str)
{
    this->m_pString = new char[strlen(str) + 1] ;
    strcpy(this->m_pString,str) ;
    this->m_size = strlen(str) ;
}

MyString::MyString(const MyString &myString)
{
    this->m_pString = new char[strlen(myString.m_pString) + 1] ;
    strcpy(this->m_pString, myString.m_pString) ;
    this->m_size = myString.m_size ;
}

void MyString::show() const
{
    cout<<this->m_pString<<"\tsize = "<<this->m_size<<endl ;
}

MyString::~MyString()
{
    if(this->m_pString != nullptr)
    {
        delete[] this->m_pString ;
        this->m_pString = nullptr ;
    }
}

ostream & operator<<(ostream &out,MyString & str)
{
    out<<str.m_pString<<"\t"<<str.m_size;
    return  out;
}

MyString& MyString::operator=(const MyString &obj){

    if(this->m_pString != nullptr)
    {
        delete[] this->m_pString;
        this->m_pString = nullptr ;
    }
    this->m_pString = new char[strlen(obj.m_pString) + 1] ;
    strcpy(this->m_pString,obj.m_pString) ;
    this->m_size = obj.m_size ;
    return *this ;
}

istream &operator>>(istream &in, MyString &str) {

    //原有字符串中的数据先清空
    if(str.m_pString != nullptr)
    {
        delete[] str.m_pString;
        str.m_pString = nullptr ;
    }
    //用户输入字符串
    char tmp[128];
    in>>tmp;
    
    //用户输入的字符串赋值给原串
    str.m_pString = new char[strlen(tmp) +1];
    strcpy(str.m_pString,tmp);
    str.m_size = strlen(tmp) ;

    return in ;
}

MyString &MyString::operator=(const char *str) {
    delete[] this->m_pString;
    this->m_pString = new char[strlen(str) +1 ];
    strcpy(this->m_pString,str);
    this->m_size = strlen(str)  ;
    return *this;
}

char &MyString::operator[](int index) {
    return this->m_pString[index];
}

MyString MyString::operator+(const char *str) {
    unsigned  int len = this->m_size + strlen(str) +1 ;
    char *tmp = new char[len];
    memset(tmp,0,len);

    strcat(tmp,this->m_pString);
    strcat(tmp,str);

    MyString newStr(tmp);
    delete[] tmp;

    return newStr;
}

MyString MyString::operator+(const MyString &str) {
    unsigned  int len = this->m_size + strlen(str.m_pString) +1 ;

    char *tmp = new char[len];
    memset(tmp,0,len);

    strcat(tmp,this->m_pString);
    strcat(tmp,str.m_pString);

    MyString newStr(tmp);
    delete[] tmp;

    return newStr;
}

bool MyString::operator==(const MyString &str) {
    if((strcmp(this->m_pString,str.m_pString) == 0)
    && (this->m_size == str.m_size) )
        return true;
    return false;
}

bool MyString::operator!=(const MyString &str) {
    if((strcmp(this->m_pString,str.m_pString) != 0)
       || (this->m_size != str.m_size) )
        return true;
    return false;

}




