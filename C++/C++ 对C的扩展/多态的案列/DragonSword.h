//屠龙宝刀类
#pragma once
#include <iostream>
#include <string>
#include "weapon.h"

using namespace std;

class DragonSword:public Weapon
{
public:
    DragonSword();
    //获取基础伤害
    virtual int getBaseDamage();
    //获取吸血
    virtual int getSuckBlood();
    //获取是否定身
    virtual bool getHold() ;
    //获取是否暴击
    virtual bool getCrit() ;

    //获取吸血率
    int suckrate;
    //获取定身率
    int holdrate;
    //获取暴击率
    int critrate;

    //  判断是否触发特性
    bool isTrigger(int rate);


    string m_WeaponName;
    int m_BaseDamage;

};