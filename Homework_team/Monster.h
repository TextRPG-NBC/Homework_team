#pragma once

#include "CommonInclude.h"

class Monster {
public:
	~Monster() {}

	void takeDamage(int damage);
	// Todo : 아이템 떨어뜨리는 로직 작성

	std::string getName() { return name; }
	int getHealth() { return health; };
	int getAttack() { return attack; }

protected:
	std::string name;
	int health;
	int attack;
};