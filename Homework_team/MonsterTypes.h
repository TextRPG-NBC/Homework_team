#pragma once

#include "CommonInclude.h"
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin(int level) 
	{
		name = "Goblin";
		health = level * (rand() % 11 + 20);	// 체력: (레벨 × 20) ~ (레벨 × 30)
		attack = level * (rand() % 6 + 5);		// 공격력: (레벨 × 5) ~ (레벨 × 10)
	}
};

class Orc : public Monster
{
public:
	Orc(int level) {
		name = "Orc";
		health = level * (rand() % 11 + 20);	// 체력: (레벨 × 20) ~ (레벨 × 30)
		attack = level * (rand() % 6 + 5);		// 공격력: (레벨 × 5) ~ (레벨 × 10)
	}
};

class Troll : public Monster
{
public:
	Troll(int level) {
		name = "Troll";
		health = level * (rand() % 11 + 20);	// 체력: (레벨 × 20) ~ (레벨 × 30)
		attack = level * (rand() % 6 + 5);		// 공격력: (레벨 × 5) ~ (레벨 × 10)
	}
};

class BossMonster : public Monster
{
public:
	BossMonster(int level) {
		name = "BossMonster";
		health = level * (rand() % 16 + 30);	// 체력: (레벨 × 30) ~ (레벨 × 45)
		attack = level * (rand() % 8 + 8);		// 공격력: (레벨 × 8) ~ (레벨 × 15)
	}
};

