#pragma once
#include <iostream>
#include <string>
#include "DragonSword.h"

class Monster;

class Hero
{
public:
    string m_Name;
    int m_Atk;
    int m_Def;
    int m_Hp;
    Weapon *weapon;

    Hero();
    void EquipWeapon(Weapon * pWeapon);
    void Attack(Monster * monster);
};