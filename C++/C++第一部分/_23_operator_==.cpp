#include <iostream>
#include <cstring>


using namespace std;

class Complex{
public:
    Complex(char* name,int id,int age){
        this->pName = new char[strlen(name) + 1];
        strcpy(this->pName, name);
        this->mID = id;
        this->mAge = age;
    }
    //重写拷贝构造
    Complex(const Complex &obj)
    {
        this->pName = new char[strlen(obj.pName) +1] ;
        strcpy(this->pName,obj.pName) ;
        this->mAge = obj.mAge;
        this->mID = obj.mID ;
    }
    //重载==号操作符
    bool operator==(const Complex& complex){
        if (strcmp(this->pName,complex.pName) == 0 &&
            this->mID == complex.mID &&
            this->mAge == complex.mAge){
            return true;
        }
        return false;
    }
    //重载!=操作符
    bool operator!=(const Complex& complex){
        if (strcmp(this->pName, complex.pName) != 0 ||
            this->mID != complex.mID ||
            this->mAge != complex.mAge){
            return true;
        }
        return false;
    }
    ~Complex(){

            delete[] this->pName ;
    }
private:
    char* pName;
    int mID;
    int mAge;
};
void test(){
    Complex complex1((char *)"aaa", 10, 20);

    Complex complex2((char *)"bbb", 10, 20);
    if (complex1 == complex2){ cout << "相等!" << endl; }
    if (complex1 != complex2){ cout << "不相等!" << endl; }

    Complex p1(complex1);
    if(complex1 == p1){cout<<"相等"<<endl; }
    /*
     * APP(2822,0x11030ae00) malloc: *** error for object 0x7f8b05c05a20: pointer being freed was not allocated
     * APP(2822,0x11030ae00) malloc: *** set a breakpoint in malloc_error_break to debug
     */


    //这个报错了，原因是调用了拷贝构造，造成了浅拷贝的问题，解决问题的办法就是重新写拷贝构造
    //类里含有指针且动态分配内存的，当释放的时候，就需要考虑到 拷贝构造和=运算符的重载
}


int main()
{
    test();

    return  0 ;
}