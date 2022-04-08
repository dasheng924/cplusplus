#include <iostream>
#include <queue>

using namespace std;

void test01()
{
    queue<int> q;
    q.push(23);
    q.push(24);
    q.push(25);
    q.push(26);

    while (!q.empty())
    {
        cout<<"\ttop value"<<q.front();
        cout<<"\tback vale:"<<q.back();
        q.pop();
        
    
    }
}


int main() {

    test01();


    return 0;
}
