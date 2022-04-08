#include <iostream>
#include <string>

using namespace std;

class MyException
{
public:
    MyException(string msg)
    {
        m_msg = msg;
    }
    void show()
    {
        cout<<m_msg<<endl;
    }
private:
    string m_msg;
};

class Person
{
public:
    Person()
    {
        cout<<"cons"<<endl;
    }
    ~Person(){cout<<"desc"<<endl;}
};

int divv(int a,int b)
{
    if(b == 0)
    {
        Person p;
        throw MyException("除数为0");
    }
    return a/b;
}



void test(int a,int b)
{
    int ret=0;
    try {
    divv(a,b);
    } catch (int) {

        throw ;
    } catch(double){

        throw ;
    } catch(MyException &e){
        e.show();
    } catch(...){
        throw ;
    }

   
}

int main()
{
    int a;
    int b;
    cin>>a;
    cin>>b;
    


    try {
        test(a,b);
    } catch (int) {
        cout<<"int"<<endl;
    } catch(double){
        cout<<"double"<<endl;
    } catch(...){
        cout<<"..."<<endl;
    }



    return 0;
}
