#include <iostream>
#include <initializer_list>

using namespace std;


int sum(initializer_list<int> ll)
{
    int sum = 0;
    
    for(auto p = ll.begin();p!=ll.end();++p)
    {
        sum += *p;
    }

    return sum;
}

int main(void)
{

    int ret = sum({10,23,1,3});

    cout<<"sum="<<ret<<endl;

    return 0;
}