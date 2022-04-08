#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

class Worker
{
public:
    string m_name;
    int m_money{};
};

enum BUMEN{P,M,H};
void createWorker(vector<Worker> & v)
{

    string str = "ABCDE";
    for(int i = 0;i<5;++i)
    {
      Worker w;
      w.m_name = string("员工") + str[i];
      srand((unsigned int)time(nullptr));
      w.m_money = rand()%10000 + 10000;
      v.push_back(w);
    }
}

void setGroup(vector<Worker> &v,multimap<int,Worker> &m)
{
    int departmentId = 0;
    for(vector<Worker>::iterator it = v.begin();it != v.end();++it)
    {
        //srand((unsigned int)time(NULL));
        departmentId = rand()%3+1;
        //将员工插入
        m.insert(make_pair(departmentId,*it));
    }
}

void showInfo(multimap<int,Worker> &m,enum BUMEN p)
{
    int count = m.count(p);
    //cout<<count<<endl;
    int index = 0;
    multimap<int,Worker>::iterator  pos = m.find(p);
    for(;pos != m.end(),index<count;pos++)
    {
        cout<<pos->second.m_name<<"\t部门"<<pos->first<<"\t员工工资:"<<pos->second.m_money<<endl;
        index++;
    }
}

void showGroup(multimap<int,Worker> &m)
{
    //enum {P,M,H};
    //P 部门
    cout<<"P 部门"<<endl;
    showInfo(m,P);

    cout<<"M 部门"<<endl;
    showInfo(m,M);

    cout<<"H 部门"<<endl;
    showInfo(m,H);




}
int main() {
   vector<Worker> v;
   //创建5名员工
   createWorker(v) ;

   for(auto &i:v)
       cout<<i.m_name<<" "<<i.m_money<<endl;

   //设置分组
   //分组的multimap容器
   multimap<int,Worker> m;
   setGroup(v,m);
   showGroup(m);





    return 0;
}
