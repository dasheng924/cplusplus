#include <iostream>
#include <string>

using namespace std;

class T1{
public:
    static int get()
    {
        return 10;
    }
};

class T2{
public:
    static string  get(){
        return "hello man";
    }
};

template<class T>
void func(void)
{
    auto v = T::get();
    cout<<"v = "<<v<<endl;
}

int main()
{
    func<T1>();
    func<T2>();

    return 0;
}