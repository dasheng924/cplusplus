#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

class Complex
{
public:
    Complex():m_num(10){}
    void mul(int x)
    {
        lock_guard<mutex> locker(m_mutex);
        m_num *= x;
    }
    void div(int x)
    {

        lock_guard<mutex> locker(m_mutex);
        m_num /= x;
    }
    void add(int x)
    {

        lock_guard<mutex> locker(m_mutex);
         m_num += x;
    }
    void all(int x)
    {

        lock_guard<mutex> locker(m_mutex);
        mul(x);
        div(x);
        add(x);
    }

    void get()
    {
        cout<<"m_num="<<m_num<<endl;
    }

private:
    int m_num;
    mutex m_mutex;
};


int main()
{

    Complex c;
    c.all(10);
    c.get();

    return 0;
}
