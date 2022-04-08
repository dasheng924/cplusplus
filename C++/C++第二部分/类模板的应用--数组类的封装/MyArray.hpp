#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class MyArray
{
public:
    explicit MyArray(int capacity) //防止隐式类型转换
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->m_pArray = new T[this->m_capacity];
    }
    MyArray(const MyArray<T> & array)
    {
        this->m_capacity = array.m_capacity;
        this->m_size = array.m_size;
        this->m_pArray = new T[array.m_capacity];
        for(int i = 0;i<array.m_size;++i)
        {
            this->m_pArray[i] = array.m_pArray[i];
        }
    }
    ~MyArray()
    {
        if(this->m_pArray != nullptr)
        {
            delete[] this->m_pArray;
            this->m_pArray = nullptr;
        }
    }

    MyArray& operator=(const MyArray<T> &array)
    {
        if(this->m_capacity != nullptr)
        {
            delete[] this->m_capacity;
            this->m_capacity = nullptr;
        }

        this->m_capacity = array.m_capacity;
        this->m_size = array.m_size;
        this->m_pArray = new T[array.m_capacity];
        for(int i = 0;i<array.m_size;++i)
        {
            this->m_pArray[i] = array.m_pArray[i];
        }

        return *this;
    }

    T& operator[](int index)const
    {
        return this->m_pArray[index];
    }

    void push_back(T var)
    {
        this->m_pArray[this->m_size] = var;
        this->m_size++;
    }

    int getSize()const
    {
        return this->m_size;
    }
    int getCapacity()const
    {
        return  this->m_capacity;
    }
    

    //成员函数实现输出
    void show()const
    {
        for(int i = 0;i<this->m_size;++i)
        {
            cout<<this->m_pArray[i]<<endl;
        }
    }

private:
    T * m_pArray; //指向堆区的指针
    int m_size;
    int m_capacity;

};


class Person
{
public:
    Person(){};
    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string getName()
    {
        return this->m_name;
    }
    int getAge()
    {
        return this->m_age;
    }

private:
    string m_name;
    int m_age;
};

//全局函数实现输出,这里用的就是模板做函数参数的三种方法
#if 0

//方法1：显式的指定模板参数的类型
//show(array);
void show(const MyArray<Person> & array)
{
    for(int i = 0;i<array.getSize();++i)
    {
        cout<<"name: "<<array[i].getName()<<"\tage:"<<array[i].getAge()<<endl;
    }
}

//show(Person);
void show(const MyArray<int> & array)
{
    for(int i = 0;i<array.getSize();++i)
    {
        cout<<array[i]<<endl;
    }
}


#endif

#if 0
//方法2：参数模板化，配合模板函数使用
//show<int>(array);
template<class T>
void show(const MyArray<T> &array)
{
    for(int i = 0;i<array.getSize();++i)
    {
        cout<<array[i]<<endl;
    }
}
//对于特定类型的重载
//show<Person>(array);

template<> void show<Person>(const MyArray<Person> & array)
{
    for(int i = 0;i<array.getSize();++i)
    {
        cout<<"name: "<<array[i].getName()<<"\tage:"<<array[i].getAge()<<endl;
    }
}
#endif

#if 1

//方法3：整体模板化
//show<MyArray<int>>(array);
template<class T>
void show(const T &p)
{
    p.show();
}

//show<MyArray<Person>>(array2);
template<> void show<MyArray<Person>>(const MyArray<Person> &array)
{
    for(int i = 0;i<array.getSize();++i)
    {
        cout<<"name: "<<array[i].getName()<<"\tage:"<<array[i].getAge()<<endl;
    }
}

#endif
