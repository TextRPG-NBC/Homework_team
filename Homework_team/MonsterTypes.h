#pragma once

#include "CommonInclude.h"
#include "Monster.h"
#include "Item.h"

class Goblin : public Monster
{
public:
	Goblin(int level, Item* item) 
		: Monster("Goblin", level, 20, 30, 5, 10, item) {}
};

class Orc : public Monster
{
public:
	Orc(int level, Item* item) 
		: Monster("Orc", level, 20, 30, 5, 10, item) {}
};

class Troll : public Monster
{
public:
	Troll(int level, Item* item)
		: Monster("Troll", level, 20, 30, 5, 10, item) {}
};

class BossMonster : public Monster
{
public:
	BossMonster(int level, Item* item) 
		: Monster("BossMonster", level, 30, 45, 8, 15, item) {}
};

