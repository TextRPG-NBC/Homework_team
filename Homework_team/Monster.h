#pragma once

#include "CommonInclude.h"

class Item;

class Monster {
public:
	~Monster();

	void takeDamage(int damage);
	void displayMonster();
	Item* dropItem();

	std::string getName() const { return name; }
	int getHealth() const { return health; };
	int getAttack() const { return attack; }

protected:
	std::string name;
	int health;
	int attack;
	Item* item;
};