##  一、C++ 对C的增强

### 1.命名空间和全局作用域

```c++
//::全局作用域

#include <iostream>
using std::cout;
using std::endl;

int a = 10 ;//全局的变量，直接使用 ::a

namespace DS{//1.命名空间只能在全局作用域内定义
  int a = 20;
}

//2.命名空间是开放的，随时可以加入新的成员
namespace DS{
    void func(){cout<<"hello STL"<<endl;}
    namespace DS11{ //3. 命名空间是可以嵌套的
        int value =111;
    }
}
namespace DS{
  void func(void){}
 
}

void test_namespace()
{
  /*  DS1的声明是错误的
  namespace DS1{
    int value = 10;
  }
  */
}

//4.无名的命名空间，相当于给成员加上了static的修饰，作为内部链接来使用
namespace {
    int num = 33;
}


//5.命名空间的别名使用规则
 // namespace DS=DSS;

//6.using 的使用：使命名空间标识符可用
//using std::cout ; 显式指出要使用的
//using 声明的空间中遇到重载，那就是把同名一组的所有函数都标识可用
namespace TT{
  void func(int num);
  void func(int num1,int num2);
  void func(int num1,double num2);
}

using TT::func; //那就是把同名一组的所有函数都标识可用


int main(void)
{

    int a = 30 ;

    cout<<::a<<endl; //全局作用域下的a 10
    cout<<DS::a<<endl;//DS 作用域下的 20
    cout<<a<<endl;//就近原则，局部的a  30
  	cout<<DS::DS11::value<<endl; //111

    return 0;
}
```

### 2.思想
```
1.C 是面向过程的
2.C++是面向对象的，有封装，继承，多态三大特性

```

### 3.具体

```C++
1.c++ 有函数重载，引用
2.更严格的类型转换
3.函数的增强：默认参数，占位参数，函数重载
4.新增bool 类型
5.三目运算符可以做左值
```






