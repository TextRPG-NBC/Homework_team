#pragma once

#include "CommonInclude.h"

class Monster {
public:
	~Monster() {}

	void takeDamage(int damage);
	void displayMonster();
	// Todo : ������ ����߸��� ���� �ۼ�

	std::string getName() const { return name; }
	int getHealth() const { return health; };
	int getAttack() const { return attack; }

protected:
	std::string name;
	int health;
	int attack;
};