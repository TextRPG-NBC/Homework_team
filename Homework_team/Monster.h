#pragma once

#include "CommonInclude.h"

class Monster {
public:
	~Monster() {}

	void takeDamage(int damage);
	// Todo : ������ ����߸��� ���� �ۼ�

	std::string getName() { return name; }
	int getHealth() { return health; };
	int getAttack() { return attack; }

protected:
	std::string name;
	int health;
	int attack;
};