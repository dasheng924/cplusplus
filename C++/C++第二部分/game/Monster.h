#pragma  once
#include <iostream>
#include <string>
#include "Hero.h"

using namespace  std;

class Monster
{
public:
    Monster();
    string m_name;
    int m_Hp;
    int m_Atk;
    int m_Def;
    bool m_Hold;
    void Attack(Hero *hero) ;




};