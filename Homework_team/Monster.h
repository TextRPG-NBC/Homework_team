#pragma once

#include "CommonInclude.h"

class Item;

class Monster {
public:
	Monster(const std::string& name, int level, int hpMin, int hpMax, int atkMin, int atkMax, Item* item);
	virtual ~Monster() = default;

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