//武器
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Weapon //抽象类
{
public:
    //获取基础伤害
    virtual int getBaseDamage()= 0 ;
    //获取吸血
    virtual int getSuckBlood() = 0;
    //获取是否定身
    virtual bool getHold() = 0;
    //获取是否暴击
    virtual bool getCrit() = 0;



    string m_WeaponName;
    int m_BaseDamage;
};