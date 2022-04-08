#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

class Player
{
public:
    Player(string name,double score)
    {
        this->m_name = name;
        this->m_score = score;
    }

    string m_name;
    int m_score;
};

void creatPlayer(vector<Player> &v)
{
    string str="ABCDE";
    for(int i = 0;i<5;++i)
    {
        string name = "选手";
        name +=str[i];
        int score = 0;
        Player p(name,score);
        v.push_back(p);
    }

}


void setScore(vector<Player> &v)
{
    //对5个人进行打分
    for(vector<Player>::iterator it = v.begin();it != v.end();++it)
    {
        deque<int>d;
        for(int i = 0;i<10;++i)
        {
            int score = rand()%41+60;
            d.push_back(score);
        }

//        for(auto it = d.begin();it != d.end();++it)
//        {
//            cout<<*it<<" ";
//        }
//        cout<<endl;
        sort(d.begin(),d.end());
        d.pop_front();
        d.pop_back();

        int sum = 0;
        for(auto it = d.begin();it != d.end();++it)
        {
            sum += *it ;
        }
        int avg = sum /d.size();
        it->m_score = avg ;
    }
}

void showAvg(vector<Player> &v)
{
    for(auto it = v.begin();it != v.end();++it)
    {
        cout<<it->m_name<<"\t"<<it->m_score<<endl;
    }
}

int main()
{
    //创建出5为选手
    vector<Player>v;
    creatPlayer(v);

//    for(vector<Player>::iterator it = v.begin();it != v.end();++it)
//    {
//        cout<<it->m_name<<" ";
//    }
    setScore(v);
    showAvg(v);

    return 0;
}