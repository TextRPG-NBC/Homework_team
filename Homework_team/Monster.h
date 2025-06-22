#pragma once

#include "CommonInclude.h"

class Monster {
public:
	~Monster() {}

	void takeDamage(int damage);
	void displayMonster();
	// Todo : 아이템 떨어뜨리는 로직 작성

	std::string getName() const { return name; }
	int getHealth() const { return health; };
	int getAttack() const { return attack; }

protected:
	std::string name;
	int health;
	int attack;
};