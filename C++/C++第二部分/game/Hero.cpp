#include "Hero.h"
#include "weapon.h"
#include "Monster.h"


Hero::Hero()
{
    this->m_Hp = 500;
    this->m_Atk = 50;
    this->m_Def = 50;
    this->m_Name = "法师";
    this->weapon = nullptr;
}

void Hero::EquipWeapon(Weapon * pWeapon)
{
    this->weapon = pWeapon;
    cout<<"英雄"<<this->m_Name<<"装备了武器"<<this->weapon->m_WeaponName<<endl ;

}
void Hero::Attack(Monster * monster)
{
    int damage ;
    int addHp = 0;
    bool isHold = false;
    bool isCrit;
    isCrit = false;
    if(this->weapon == nullptr)
    {
        damage = this->m_Atk;
    }
    else
    {
        //基础伤害
        damage = this->m_Atk + this->weapon->getBaseDamage();
        //计算吸血
        addHp = this->weapon->getSuckBlood();

        //计算定身
        isHold = this->weapon->getHold();

        //计算暴击
        isCrit = this->weapon->getCrit();

    }
    if(addHp > 0)
    {
        cout<<"触发了吸血效果，吸血量" << addHp << endl;
    }
    if(isCrit)
    {
        damage = damage *2 ;
        cout<<"英雄的武器触发了暴击效果，怪物受到了伤害，伤害值："<<damage<<endl ;
    }
    if(isHold)
    {
        cout<<"怪物受到了定身的攻击，停止攻击一回合"<<endl ;
    }

    //设置怪物是否被定身
    monster->m_Hold = isHold;
    //计算真实的伤害
    int trueDamage = (damage - monster->m_Def)>0?damage - monster->m_Def : 1 ;
    monster->m_Hp -= trueDamage ;

    this->m_Hp += addHp;

    cout<<"英雄"<<this->m_Name<<"攻击了敌人"<<monster->m_name<<"造成了"<<trueDamage<<"伤害"<<endl ;



}