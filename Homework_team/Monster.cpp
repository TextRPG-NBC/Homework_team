#include "Monster.h"

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
