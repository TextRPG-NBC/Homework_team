#pragma once

#include "CommonInclude.h"
#include "Monster.h"
#include "Item.h"

class Goblin : public Monster
{
public:
	Goblin(int level, Item* item) 
	{
		name = "Goblin";
		health = level * RandomUtil::getInt(20, 30);	// ü��: (���� �� 20) ~ (���� �� 30)
		attack = level * RandomUtil::getInt(5, 10);		// ���ݷ�: (���� �� 5) ~ (���� �� 10)
		item = new Item(*item);
	}
};

class Orc : public Monster
{
public:
	Orc(int level, Item* item) {
		name = "Orc";
		health = level * RandomUtil::getInt(20, 30);	// ü��: (���� �� 20) ~ (���� �� 30)
		attack = level * RandomUtil::getInt(5, 10);		// ���ݷ�: (���� �� 5) ~ (���� �� 10)
		item = new Item(*item);
	}
};

class Troll : public Monster
{
public:
	Troll(int level, Item* item) {
		name = "Troll";
		health = level * RandomUtil::getInt(20, 30);	// ü��: (���� �� 20) ~ (���� �� 30)
		attack = level * RandomUtil::getInt(5, 10);		// ���ݷ�: (���� �� 5) ~ (���� �� 10)
		item = new Item(*item);
	}
};

class BossMonster : public Monster
{
public:
	BossMonster(int level, Item* item) {
		name = "BossMonster";
		health = level * RandomUtil::getInt(30, 45);	// ü��: (���� �� 30) ~ (���� �� 45)
		attack = level * RandomUtil::getInt(8, 15);		// ���ݷ�: (���� �� 8) ~ (���� �� 15)
		item = new Item(*item);
	}
};

