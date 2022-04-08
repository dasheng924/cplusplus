#include <iostream>
#include <string>
using namespace std;


int main(void)
{

    //原始字面量
    string str = "/Users/sunguosheng/Documents/\t";

    string str2 = R"path(/Users/sunguosheng/Documents/)path";

    cout<<str<<str2;

    return  0;
}
//out
///Users/sunguosheng/Documents/%    按原样输出，末尾不是'\0'，所以会出现乱码