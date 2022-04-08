#include <iostream>

using namespace std;

/*
cout.put();
cout.flush();
cout.write();
*/


int main()
{
    cout.put('a');
    cout.put('1');

    cout.flush();

    char buf[1024] = "e3dfevewv";
    cout.write(buf,sizeof(buf));



    return 0;
}