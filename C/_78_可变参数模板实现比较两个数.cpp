#include <iostream>
using namespace std;

template<typename T>
T myMax(T value)
{
    return value;
}

template<typename T,typename...Type>
T myMax(T firstArg,Type...args)
{
    cout << __PRETTY_FUNCTION__ << "\n";
    return max(firstArg,myMax(args...));
    
}

int main(void)
{

    int max_num = myMax<int>(1,23,99,67,10);
    cout<<max_num<<endl;
    return 0;
}
