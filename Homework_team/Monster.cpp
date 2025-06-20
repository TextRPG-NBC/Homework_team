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
