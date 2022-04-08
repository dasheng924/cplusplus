//小刀类
#pragma once
#include <iostream>
#include <string>
#include "weapon.h"

using namespace std;

class Knife:public Weapon
{
public:
    Knife();
    //获取基础伤害
    virtual int getBaseDamage();
    //获取吸血
    virtual int getSuckBlood();
    //获取是否定身
    virtual bool getHold() ;
    //获取是否暴击
    virtual bool getCrit() ;


    string m_WeaponName;
    int m_BaseDamage;

};