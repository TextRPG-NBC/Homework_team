#pragma once
#include "CommonInclude.h"

class Monster;
class BossMonster;
class Character;
class ItemManager;
class Item;
class Shop;

class GameManager
{
public:
	GameManager();
	~GameManager();

	Monster* generateMonster(int level);
	BossMonster* generateBossMonster(int level);
	void battle();
	void visitShop();
	void displayInventory();
	void run();

private:
	int ExperienceToReceive;		// 전투 승리 시 받는 경험치
	int GoldToReceive;				// 전투 승리 시 받는 골드
	int ProbabilityToGetItem;		// 전투 승리 시 아이템이 떨어질 확률

	ItemManager* itemManager;
	Shop* shopManager;
	Character* player;

private:
	void getItemByBattle(Item* item);
	void getPlayerName();
};

