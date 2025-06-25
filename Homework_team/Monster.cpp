#include "Monster.h"
#include "Item.h"
#include "ItemManager.h"

Monster::Monster(const std::string& name, int level, int hpMin, int hpMax, int atkMin, int atkMax, Item* item)
	:name(name), item(item)
{
	health = level * RandomUtil::getInt(hpMin, hpMax);
	attack = level * RandomUtil::getInt(atkMin, atkMax);
}

void Monster::takeDamage(int damage)
{
	if (health - damage < 0) 
	{
		health = 0;
	}
	else 
	{
		health -= damage;
	}
}

void Monster::displayMonster()
{
	std::cout << "몬스터 " << this->name << " 등장!";
	std::cout << "체력: " << this->health;
	std::cout << ", 공격력: " << this->attack << std::endl;
}

Item* Monster::dropItem()
{
	return item;
}
