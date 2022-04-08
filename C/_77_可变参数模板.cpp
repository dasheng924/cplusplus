#include <iostream>


void print(){} //0个参数的调用函数

template<typename T,typename... T2>
void print(const T& firstArg,const T2&... args)
{
  std::cout<<firstArg<<"\t除去第一个参数，后面可变参数的个数： "<<sizeof...(args)<<std::endl;
  std::cout << __PRETTY_FUNCTION__ << "\n";
  print(args...);
}

int main()
{

    print("hello",1,22.34);

    return 0;
}