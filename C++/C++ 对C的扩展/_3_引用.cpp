#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl ;
using std::string;

//1.变量名是一段内存的标识，或者是门牌号；通过变量名来申请内存；通过变量名来使用内存，引用就是给这段内存起一个别的名字

void test01()
{
    int num = 10;
    int &other_num = num;   //两个变量指向同一块内存
    cout<<"old:"<<num<<"\tnew:"<<other_num<<endl; 

    other_num++;

    cout<<"old:"<<num<<"\tnew:"<<other_num<<endl; 
/*
old:10  new:10
old:11  new:11
*/

}

 //2.定义之初就必须初始化；一旦绑定，就不可以再成为别的变量的引用；不可以为不合法的内存申请引用，比如NULL
void test02()
{
    int a = 10 ; 
    int &num = a;  //定义之初就必须初始化；一旦绑定，就不可以再成为别的变量的引用；不可以为不合法的内存申请引用，比如NULL
    
    cout<<num<<endl ;
    int b = 20;
    // int &num = b ;  redefinition of 'num'

    int &num1 = a; //可以对同一个变量起多个引用
    int &num2 = a;
    int &num3 = a;

    cout<<"num1  = "<<num1<<"\tnum2 = "<<num2<<"\tnum3 = "<<num3<<endl ;
}

//3.对数组建立引用
void test03()
{
    

#if 0
    typedef int (ARRAY_TYPE)[5] ;
    ARRAY_TYPE arr = {12,34,5,6,7} ;

    ARRAY_TYPE &o_arr = arr;

    for(int i = 0;i<5;++i)
    {
        printf("%d\t",arr[i]) ;
        printf("%d\n",o_arr[i]) ;
    }
#endif

#if 1
    int arr[5] = {1,2,3,4,5} ;
    int (&o_arr)[5] = arr ;

       for(int i = 0;i<5;++i)
    {
        printf("%d\t",arr[i]) ;
        printf("%d\n",o_arr[i]) ;
    }

#endif

}

//4.引用做函数的参数

void Swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = a;
}
void test04()
{

    int num1 = 10,num2 = 30;
    cout<<"num1 = "<<num1<<"\tnum2 = "<<num2<<endl ;

    Swap(num1,num2) ;
    cout<<"num1 = "<<num1<<"\tnum2 = "<<num2<<endl ;
}

//5.引用做函数的返回值
/*
int& func1(void)
{
    int a = 1000;  
    return a;  //局部变量的引用不能返回
    //reference to stack memory associated with local variable 'a' returned [-Wreturn-stack-address]
}
*/

int& func2(void)
{
    static int a = 1999;
    return a;
}

void test05()
{
    //int &ret = func1();
    int &ret2 = func2();

    func2() = 1; //返回值做左值，就必须返回引用


    cout<<"ret2 = "<<ret2<<endl;

    //cout<<sizeof(ret2)<<endl ;


}

//6.指针的引用
struct Teacher
{
    string name;
    int age;
};

void MallocPoint(Teacher ** p)  //指针的方式修改
{
    if(p == NULL)
        return;
    Teacher * tmp = (Teacher*)malloc(sizeof(Teacher));
    if(tmp == NULL)
        return;
    tmp->name = "alex" ;
    tmp->age = 99 ;
    *p = tmp;
}

void MallocRef(Teacher* &p) //引用的方式修改
{
    p->name = "lucy";
    p->age = 80;
}

void test06()
{
    Teacher * t = NULL;
    //通过指针修改内容

    MallocPoint(&t);
    cout<<t->name<<"\t"<<t->age<<endl;
    MallocRef(t);
    cout<<t->name<<"\t"<<t->age<<endl;



}


//7.常量的引用
void test07()
{   

    int a = 10;
    const int &num = a; 

     // num =11; // 错误，用const修饰的引用，无法通过修改引用，改变原值
 
    const int &b = 10;  //const 引用可以对字面量引用

    cout<<b<<endl ;
}



int main(void)
{
    //test01() ;

    //test02() ;

    //test03() ;

    //test04() ;

    //test05();

    //test06();

    test07() ;




    return 0 ;
}