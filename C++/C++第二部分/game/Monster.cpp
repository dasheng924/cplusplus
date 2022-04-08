
#include "Monster.h"

Monster::Monster() {
    this->m_name = "鲁班";
    this->m_Atk = 70;
    this->m_Def = 70;
    this->m_Hp = 300 ;
    this->m_Hold = false ;

}

void Monster::Attack(Hero *hero) {
    if(this->m_Hold)
    {
        cout<<"怪物"<<this->m_name<<"被定身了,无法攻击"<<endl ;
    }
    //计算攻击力
    int damage = (this->m_Atk- hero->m_Atk) > 0 ? this->m_Atk-hero->m_Atk:1 ;
    hero->m_Hp -=damage;
    cout<<"怪物"<<this->m_name<<"攻击了，英雄"<<hero->m_Name<<"造成了伤害"<<damage<<endl ;
}
