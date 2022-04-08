#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <random>
#include <deque>
#include <numeric>


using namespace std;





class Speeker
{
public:
    string m_name;
    double m_score[3]; //三轮成绩的得分数组
};


void createSpeeker(vector<int> &v,map<int,Speeker> &m)
{
    string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";

    for(int i = 0;i< nameSeed.size();++i)
    {
        Speeker sp;
        sp.m_name = string("选手")+nameSeed[i];

        for(int i= 0;i<3;i++)
        {
            sp.m_score[i] = 0;
        }

        v.push_back(i+100) ; //编号 100——123
        m.insert(make_pair(i+100,sp)) ;
    }

}


void speechDraw(vector<int> &v)
{
    shuffle(v.begin(),v.end(),mt19937(random_device()())) ;
}

//1.比赛场次 2。编号  3。比赛人员信息  4。进入下一轮的人员
void speechContest(int index,vector<int> &v1,map<int,Speeker> &m,vector<int> &v2)
{
    deque<double> d; // 存放选手分数
    multimap<double,int,greater<int>> groupMap; //key-->分数 value --》选手编号
    int num = 0;
    for(auto speeker_num:v1)
    {
        num++;
        for(int i = 0;i<10;++i)
        {
            double score = rand()%41+60.13+2.33*(i+1) ; //60~100
            d.push_back(score);
        }
        //排序
        sort(d.begin(),d.end()) ;
        //去最高 最低分
        d.pop_back();
        d.pop_front();
        double sum = accumulate(d.begin(),d.end(),0);
        double avg = sum / d.size() ;
        //将平均分放到容器中
        m[speeker_num].m_score[index-1] = avg ;

        //每6个人取前三名晋级

        //临时容器保存6个人
        //临时容器存入数据
        groupMap.insert(make_pair(avg,speeker_num));


        if(num %6 ==0)
        {
            cout<<"已经存满6个人，信息输出："<<endl;
            for(auto ii:groupMap)
            {
                //cout<<"员工编号"<<ii.second<<"\t平均分"<<ii.first<<endl;
                cout<<"员工编号"<<ii.second<<"\t员工姓名："<<m[ii.second].m_name<<"\t平均分"<<ii.first<<endl;
            }

            //取前三名

            int num_c = 0;
            for(auto it = groupMap.begin();it != groupMap.end(),num_c < 3;++it,++num_c)
            {
                cout<<"员工编号"<<it->second<<endl;
                v2.push_back(it->second) ;
            }
            groupMap.clear();
        }
    }
}


void showScore(int index,vector<int> &v,map<int,Speeker> & m)
{
    cout<<"第"<<index<<"轮，比赛成绩，如下："<<endl;

    for(auto it:m)
        cout<<"选手编号："<<it.first<<"\t姓名:"<<it.second.m_name<<"\t分数："<<it.second.m_score[index-1]<<endl;

    cout<<"晋级选手编号："<<endl;
    for(auto i:v)
        cout<<i<<endl;
}

int main() {

    vector<int>v1 ;//选手编号
    map<int,Speeker>m;//选手编号和选手信息

    //产生选手
    createSpeeker(v1,m) ;

    //抽签
    speechDraw(v1);

    //选手比赛
    vector<int>v2 ;//进入下一轮比赛人的编号
    speechContest(1,v1,m,v2);

    //显示比赛结果
    showScore(1,v2,m) ;

    //第二轮
    speechDraw(v2);
    vector<int>v3;
    speechContest(2,v2,m,v3);
    showScore(2,v3,m);

    //第三轮
    speechDraw(v3);
    vector<int>v4;
    speechContest(3,v3,m,v4);
    showScore(3,v4,m);





//   for(auto &i:v1)
//   {
//       cout<<"选手编号:"<<i<<endl;
//   }











    return 0;
}
