#include "Hero.h"
#include "weapon.h"


Hero::Hero()
{
    this->m_Hp = 500;
    this->m_Atk = 50;
    this->m_Def = 50;
    this->m_Name = "法师";
    this->weapon = nullptr;
}

void Hero::EquipWeapon(Weapon * weapon)
{
    this->weapon = weapon;
    cout<<"英雄"<<this->m_Name<<"装备了武器"<<this->weapon->m_BaseDamage<<endl;

}
void Hero::Attack(Monster * monster)
{

}