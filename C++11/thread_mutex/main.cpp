#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

class Test
{
public:
    static int m_num;
    static void show_static();

    void print_hello()
    {
        cout<<"hello"<<endl;
    }
};

int Test::m_num = 999;
void Test::show_static()
{
    m_num++;
    cout<<"m_num"<<m_num<<endl;
}



int main()
{
    Test t;
    cout<<t.m_num<<" "<<Test::m_num<<endl;
    Test::show_static();
    t.show_static();
    cout<<t.m_num<<" "<<Test::m_num<<endl;

    {
        static int ok ;
        cout<<"ok="<<ok<<endl;

    }

    //1.static_cast
    double d = static_cast<double>(12);
    cout<<d<<endl;
    //2.const_cast
    const char *name = "Alex";
    char *old_name = const_cast<char *>(name);
    cout<<old_name<<endl;




    return 0;
}
