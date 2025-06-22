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

	int ExperienceToReceive = 50;	// ���� �¸� �� �޴� ����ġ
	int GoldToReceive;				// ���� �¸� �� �޴� ���
	int ProbabilityToGetItem = 30;	// ���� �¸� �� �������� ������ Ȯ��
};

