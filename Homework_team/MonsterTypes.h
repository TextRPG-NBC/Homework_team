#pragma once

#include "CommonInclude.h"
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin(int level) 
	{
		name = "Goblin";
		health = level * (rand() % 11 + 20);	// ü��: (���� �� 20) ~ (���� �� 30)
		attack = level * (rand() % 6 + 5);		// ���ݷ�: (���� �� 5) ~ (���� �� 10)
	}
};

class Orc : public Monster
{
public:
	Orc(int level) {
		name = "Orc";
		health = level * (rand() % 11 + 20);	// ü��: (���� �� 20) ~ (���� �� 30)
		attack = level * (rand() % 6 + 5);		// ���ݷ�: (���� �� 5) ~ (���� �� 10)
	}
};

class Troll : public Monster
{
public:
	Troll(int level) {
		name = "Troll";
		health = level * (rand() % 11 + 20);	// ü��: (���� �� 20) ~ (���� �� 30)
		attack = level * (rand() % 6 + 5);		// ���ݷ�: (���� �� 5) ~ (���� �� 10)
	}
};

class BossMonster : public Monster
{
public:
	BossMonster(int level) {
		name = "BossMonster";
		health = level * (rand() % 16 + 30);	// ü��: (���� �� 30) ~ (���� �� 45)
		attack = level * (rand() % 8 + 8);		// ���ݷ�: (���� �� 8) ~ (���� �� 15)
	}
};

