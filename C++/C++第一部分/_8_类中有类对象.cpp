#include <iostream>
#include <string>

using namespace std;



class Phone
{
public:
    
    Phone(string phone):m_phone(phone){cout<<"Phone 构造函数"<<endl;}
    string GetPhone(){return m_phone;}
    ~Phone(){cout<<"Phone析构函数"<<endl;}

private:
    string m_phone;
};

class Game
{
public:
    
    Game(string game):m_game(game){cout<<"Game 的构造函数"<<endl;}
    string GetGame(){return m_game;}
    ~Game(){cout<<"Game析构函数"<<endl;}

private:
    string m_game;

};

class Person
{
public:
    
    Person(string person,string phone,string game):m_person(person),myPhone(phone),myGame(game)
    {cout<<"Person 的构造函数"<<endl;}
    void show(){cout<<m_person<<"用"<<myPhone.GetPhone()<<"手机，在玩"<<myGame.GetGame()<<"游戏"<<endl;}
    ~Person(){cout<<"Person 的析构函数"<<endl;}

public:
    string m_person;
    Game myGame;
    Phone myPhone;
    

    //调用构造函数的顺序：按照定义时候的顺序，与构造函数初始化列表是没有关系
    
};

int main(void)
{

    Person p("alex","xiaomi","wzry") ;
    p.show();


    return 0;
}