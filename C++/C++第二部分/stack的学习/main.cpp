#include <iostream>
#include <stack>

using namespace std;


void test01()
{
    stack<int> s;
    s.push(1);
    s.push(10);
    s.push(11);
    s.push(21);
    s.push(99);
    s.push(20);

    //这个不叫遍历，所以元素都没有了，没有迭代器
    while (s.size() != 0)
    {
        cout<<"栈顶元素"<<s.top()<<"\t";
        s.pop();
    }
}


int main() {

    test01();






    return 0;
}
