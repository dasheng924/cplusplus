#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
#if 0
    shared_ptr<int> ptr(new int{23});
    weak_ptr<int> wp1 = ptr;
    weak_ptr<int> wp2(ptr);
    weak_ptr<int> wp3(wp1);

    cout<<wp1.use_count()<<endl;
    cout<<wp2.use_count()<<endl;
    cout<<wp3.use_count()<<endl;
   
    cout<<ptr.use_count()<<endl;
#endif

    shared_ptr<int> sp1,sp2;
    weak_ptr<int> wp;

    sp1 = make_shared<int>(520);

    wp = sp1; //weak_ptr的初始化
    sp2 = wp.lock();
    cout<<"use_count="<<wp.use_count()<<endl;




    return 0;
}