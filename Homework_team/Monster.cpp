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
	std::cout << "몬스터 " << this->name << " 등장!";
	std::cout << "체력: " << this->health;
	std::cout << ", 공격력: " << this->attack << std::endl;
}
