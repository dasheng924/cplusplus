#include <iostream>

using namespace std;


class Animal
{
public:
    virtual void speak() //虚函数：迟绑定，在运行时确定函数的地址
    {
        cout<<"动物在说话"<<endl ;
    }
};

class Cat:public Animal
{
public:
    void speak(){cout<<"Cat 在说话"<<endl ;}
};

//多态：父类的指针或者引用 指向子类对象
void doSpeak(Animal &animal)
{
    animal.speak();
}

void test01()
{
    Cat c;
    doSpeak(c);
}
void test02()
{
    Animal *animal = new Cat;
    //*((int*)*(int*)animal + 1)  //猫吃鱼的地址
    
   
   

}

int main()
{   
    //test01();
    test02();

    return 0;
}
