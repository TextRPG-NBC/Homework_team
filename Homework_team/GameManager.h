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
	int ExperienceToReceive;		// ���� �¸� �� �޴� ����ġ
	int GoldToReceive;				// ���� �¸� �� �޴� ���
	int ProbabilityToGetItem;		// ���� �¸� �� �������� ������ Ȯ��

	ItemManager* itemManager;
	Shop* shopManager;
	Character* player;

private:
	void getItemByBattle(Item* item);
	void getPlayerName();
};

