#pragma once
#include "CommonInclude.h"

class Monster;
class BossMonster;
class Character;

class GameManager
{
public:
	Monster* generateMonster(int level);
	BossMonster* generateBossMonster(int level);
	bool battle(Character* player);
	void visitShop(Character* player);
	void displayInventory(Character* player);

private:
	void getItemByBattle(Character* player);

	int ExperienceToReceive = 50;	// 전투 승리 시 받는 경험치
	int GoldToReceive;				// 전투 승리 시 받는 골드
	int ProbabilityToGetItem = 30;	// 전투 승리 시 아이템이 떨어질 확률
};

