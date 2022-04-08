//::全局作用域

#include <iostream>
using std::cout;
using std::endl;

int a = 10 ;//全局的变量

namespace DS{

    int a = 20;
}


//2.命名空间是开放的，随时可以加入新的成员
namespace DS{
    void func(){cout<<"hello STL"<<endl;}
    namespace DS11{ //3. 命名空间是可以嵌套的
        int value =111;
    }
}

 void test_namespace()
{
  //1.命名空间只能在全局作用域内定义
  /*   错误的操作
  namespace DS1{
    int value = 10;
  }
  */
  
}
  
//4.无名的命名空间，相当于给成员加上了static的修饰，作为内部链接来使用
namespace {
    int num = 33;
}


int main(void)
{

    int a = 30 ;

    cout<<::a<<endl;
    cout<<DS::a<<endl;
    cout<<a<<endl;
    DS::func();
    cout<<DS::DS11::value<<endl;

    return 0;
}