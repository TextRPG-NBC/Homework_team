#include "Monster.h"
#include "Item.h"
#include "ItemManager.h"

Monster::~Monster()
{
	delete item;
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
	std::cout << "���� " << this->name << " ����!";
	std::cout << "ü��: " << this->health;
	std::cout << ", ���ݷ�: " << this->attack << std::endl;
}

Item* Monster::dropItem()
{
	return item;
}
