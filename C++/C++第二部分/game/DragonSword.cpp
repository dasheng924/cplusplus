#include "DragonSword.h"
#include <ctime>

DragonSword::DragonSword()
{
    this->m_BaseDamage = 20;
    this->m_WeaponName ="屠龙宝刀";
    this->suckrate = 20;
    this->holdrate = 30;
    this->critrate = 35;

}
//获取基础伤害
int DragonSword::getBaseDamage()
{
    return this->m_BaseDamage;
}
//获取吸血
int DragonSword::getSuckBlood()
{
    if(isTrigger(suckrate))
    {
        return this->m_BaseDamage * 0.5;
    }
}
//获取是否定身
bool DragonSword::getHold()
{
    if(isTrigger(holdrate))
        return true;
    return false;
}
//获取是否暴击
bool DragonSword::getCrit()
{
    if(isTrigger(critrate))
        return true;
    return false;
}

//  判断是否触发特性
bool DragonSword::isTrigger(int rate)
{
    srand(time(NULL));
    int num = rand()%100 +1 ;
    if(num < rate)
        return true;
    else
        return false;

}
/*
//获取吸血率
int suckrate;
//获取定身率
int holdrate;
//获取暴击率
int critrate;
*/

