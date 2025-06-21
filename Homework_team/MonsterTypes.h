#pragma once

#include "CommonInclude.h"
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin(int level) 
	{
		name = "Goblin";
		health = level * RandomUtil::getInt(20, 30);	// 체력: (레벨 × 20) ~ (레벨 × 30)
		attack = level * RandomUtil::getInt(5, 10);		// 공격력: (레벨 × 5) ~ (레벨 × 10)
	}
};

class Orc : public Monster
{
public:
	Orc(int level) {
		name = "Orc";
		health = level * RandomUtil::getInt(20, 30);	// 체력: (레벨 × 20) ~ (레벨 × 30)
		attack = level * RandomUtil::getInt(5, 10);		// 공격력: (레벨 × 5) ~ (레벨 × 10)
	}
};

class Troll : public Monster
{
public:
	Troll(int level) {
		name = "Troll";
		health = level * RandomUtil::getInt(20, 30);	// 체력: (레벨 × 20) ~ (레벨 × 30)
		attack = level * RandomUtil::getInt(5, 10);		// 공격력: (레벨 × 5) ~ (레벨 × 10)
	}
};

class BossMonster : public Monster
{
public:
	BossMonster(int level) {
		name = "BossMonster";
		health = level * RandomUtil::getInt(30, 45);	// 체력: (레벨 × 30) ~ (레벨 × 45)
		attack = level * RandomUtil::getInt(8, 15);		// 공격력: (레벨 × 8) ~ (레벨 × 15)
	}
};

