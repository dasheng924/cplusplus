#include "MyArray.hpp"



void test01()
{
    MyArray<int> array(5);
    for(int i = 0;i<5;++i)
    {
        array.push_back(i+10);
    }
    array.show();
    show<MyArray<int>>(array);
}

void test02()
{
    Person p1("alex", 23);
    Person p2("Lucy", 25);
    Person p3("Gooo", 29);
    Person p4("Tiny", 21);

    MyArray<Person> array2(10);
    array2.push_back(p1);
    array2.push_back(p2);
    array2.push_back(p3);
    array2.push_back(p4);

    show<MyArray<Person>>(array2);

}

int main() {

    test02();


    return 0;
}


class exception ;