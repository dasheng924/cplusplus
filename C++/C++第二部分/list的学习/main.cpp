#include <iostream>
#include <list>
#include <string>
#include <utility>

using namespace std;
bool myCompare(int v1,int v2)
{
    return v1>v2;
}

void show(const list<int>& L)
{
    for(int it : L)
    {
        cout<<it<<"\t";
    }
    cout<<endl;
}
void rshow(list<int> &L)
{
    for(auto it = L.rbegin();it !=L.rend();++it)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
}

//list 的构造函数
void test01()
{
    list<int>L1(5,3);
    show(L1);

    list<int> L2(L1.begin(),L1.end());
    L2.push_back(100);
    L2.push_front(999);

    show(L2);//顺序打印
    rshow(L2);//逆序打印

}

//list的插入和删除
void test02()
{
    /*
    push_back(elem);//在容器尾部加入一个元素
    pop_back();//删除容器中最后一个元素
    push_front(elem);//在容器开头插入一个元素
    pop_front();//从容器开头移除第一个元素
    insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
    insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
    insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
    clear();//移除容器的所有数据
    erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
    erase(pos);//删除pos位置的数据，返回下一个数据的位置。
    remove(elem);//删除容器中所有与elem值匹配的元素。
    */

    list<int> L1;
    for(int i = 0;i<10;i++)
    {
        L1.push_front(i+1);
    }
    show(L1);//10	9	8	7	6	5	4	3	2	1
    auto it = L1.insert(L1.end(),2,9);
    show(L1);//10	9	8	7	6	5	4	3	2	1	9	9
    cout<<*it<<endl; //insert 插入返回的是新插入元素的位置 //9

   // auto itt = L1.erase(L1.begin(),it); //erase 返回的是删除区间下一个元素的位置
    //cout<<*itt<<endl; // 9

    L1.remove(7); //删除值为7 的元素
    show(L1);

    cout<<"L1 的大小为"<<L1.size()<<endl;





}

//赋值操作
void test03()
{
    /*
    assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
    assign(n, elem);//将n个elem拷贝赋值给本身。
    list& operator=(const list &lst);//重载等号操作符
    swap(lst);//将lst与本身的元素互换。
    */

    list<int> L1(5,2);
    list<int> L2;
    L2.assign(L1.begin(),L1.end());
    show(L2);

}

//list的反转
void test04()
{
    list<int> L1;
    for(int i = 0;i<10;i++)
    {
        L1.push_front(i+1);
    }
    show(L1);//10	9	8	7	6	5	4	3	2	1

    L1.reverse();
    show(L1);
    cout<<L1.front()<<"\t"<<L1.back()<<endl;
    L1.push_front(99);
    L1.sort();//从小到大
    show(L1);

    L1.sort(myCompare);//从大到小
    show(L1);
}


//自定义类型
class Person
{
public:
    Person(string name,int age)
    {
        this->m_name = move(name);
        this->m_age = age;
    }

    bool operator==(const Person &p) const
    {
        if(this->m_name == p.m_name && this->m_age == p.m_age)
            return true;
        return false;
    }




    string m_name;
    int m_age;
};
bool showshow(Person &p1,Person &p2)
{
    if(p1.m_age > p2.m_age)
    {
        return true;
    }
    return false;


    /*年龄相同的情况下，按照身高进行排序
     * if(p1.age == p2.age)
     * {
     *      return p1.height > p2.height;
     *  }
     *  else
     *  {
     *      return p1.age > p2.age;
     *   }
     */
}





void test05()
{
    list<Person> l1;
    l1.push_front(Person ("鲁班",22));
    l1.push_front(Person ("后裔",12));
    l1.push_front(Person("牛魔王",120));
    l1.push_front(Person("女娲",99));

    cout<<"----------------------"<<endl;
    for(auto & it : l1)
    {
        cout<<"name:"<<it.m_name<<"\tage:"<<it.m_age<<endl;

    }

    l1.sort(showshow);


    cout<<"----------------------"<<endl;
    for(auto & it : l1)
    {
        cout<<"name:"<<it.m_name<<"\tage:"<<it.m_age<<endl;

    }

    Person pp = Person ("鲁班",22);
    l1.remove(pp);

    cout<<"----------------------"<<endl;
    for(auto it = l1.begin();it != l1.end();++it)
    {
        cout<<"name:"<<it->m_name<<"\tage:"<<it->m_age<<endl;
    }



}

int main() {

//    test01();
//    test02();
//    test03();
//    test04();
    test05();



    return 0;
}
