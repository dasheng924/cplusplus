#include <iostream>
#include <string>

using namespace std;

void test()
{
    pair<string,int> p (string("alex"),23);

    //getValue
    cout<<p.first<<"\t"<<p.second<<endl;

    pair<string,int>p1 = make_pair(string("Lucy"),12);
    cout<<p1.first<<"\t"<<p1.second<<endl;
}

int main() {
    test();
    return 0;
}
