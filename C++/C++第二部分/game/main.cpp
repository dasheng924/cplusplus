#include "Hero.h"
#include "weapon.h"
#include "knife.h"
#include "DragonSword.h"
#include "Monster.h"

using  namespace  std ;

void play()
{
    // 创建怪物
    auto * monster = new Monster;
    //创建英雄
    Hero * hero = new Hero;

    //创建武器
    Weapon * knife = new Knife;
    Weapon * dragonSword = new DragonSword;

    //让用户选择武器
    cout<<"请选择武器"<<endl ;
    cout<<"1    赤手空拳"<<endl ;
    cout<<"2    小刀"<<endl ;
    cout<<"3    屠龙刀"<<endl ;

    int op = 0;
    cin>>op;
    switch (op) {
        case 1:
            cout<<"太年轻"<<endl ;
            break;
        case 2:
            hero->EquipWeapon(knife);
            break;
        case 3:
            hero->EquipWeapon(dragonSword);
            break;
        default:
            break;
    }
    getchar();
    int round = 1;
    while (true)
    {
        getchar();
        system("clear");
        cout<<"--------当前第"<<round<<"几回合---------"<<endl;
        if(hero->m_Hp <= 0)
        {
            cout<<"英雄"<<hero->m_Name<<"GAME OVER！"<<endl ;
            break;
        }
        hero->Attack(monster);
        if(monster->m_Hp <= 0)
        {
            cout<<"怪物"<<monster->m_name<<"死亡💀"<<endl;
        }
        monster->Attack(hero);

    }

    delete monster;
    delete hero;


}

int main()
{
    play();

    return  0 ;
}