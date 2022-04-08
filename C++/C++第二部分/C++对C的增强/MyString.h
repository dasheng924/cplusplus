//
// Created by 孙国盛 on 2021/5/18.
//

#ifndef APP_MYSTRING_H
#define APP_MYSTRING_H

#include <iostream>
using namespace std ;

class MyString
{
public:
    //MyString str("abc") ;
    MyString(const char *) ;
    MyString(const MyString &myString) ;

    void show() const;
    friend ostream & operator<<(ostream &out,MyString & str) ;
    friend istream & operator>>(istream &in,MyString &str) ;

    MyString& operator=(const MyString &obj);
    MyString& operator=(const char* str);

    char& operator[](int index);

    MyString operator+(const char *str);
    MyString operator+(const MyString &str);

    bool operator==(const MyString & str);
    bool operator!=(const MyString & str);

    ~MyString();


private:
    char * m_pString ;
    unsigned int m_size ;
};






#endif //APP_MYSTRING_H
