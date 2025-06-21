#include "GameManager.h"
#include "Monster.h"
#include "MonsterTypes.h"
#include "character.h"

Monster* GameManager::generateMonster(int level)
{
	int NumberOfMonster = 3;
	int RandomValue = RandomUtil::getInt(0, NumberOfMonster - 1);

	Monster* newMonster = nullptr;

	if (RandomValue == 0)
	{
		newMonster = new Goblin(level);
	}
	else if (RandomValue == 1)
	{
		newMonster = new Orc(level);
	}
	else if (RandomValue == 2)
	{
		newMonster = new Troll(level);
	}
	newMonster->displayMonster();

	return newMonster;
}

BossMonster* GameManager::generateBossMonster(int level)
{
	BossMonster* newBossMonster = new BossMonster(level);
	newBossMonster->displayMonster();

	return newBossMonster;
}

bool GameManager::battle(Character* player)
{
	bool IsCharacterDead = false;
	
	Monster* newMonster = nullptr;
	// ���� 10 �̸� �� �Ϲ� ���� ��ȯ
	if (player->level < 10) 
	{
		newMonster = generateMonster(player->level);
	}
	// ���� 10 �޼� �� ���� ���� ��ȯ
	else
	{
		newMonster = generateBossMonster(player->level);
	}

	assert(newMonster != nullptr);

	// ���� ���
	while (1) {
		// �÷��̾ ���� ����
		cout << player->name << "��(��) " << newMonster->getName() << "�� �����մϴ�! ";
		newMonster->takeDamage(player->attackPower);

		// ���� óġ
		if (newMonster->getHealth() <= 0) 
		{
			cout << newMonster->getName() << " óġ!" << endl;
			break;
		}
		else 
		{
			cout << newMonster->getName() << " ü��: " << newMonster->getHealth() << endl;
		}

		// �÷��̾ ���� ����
		cout << newMonster->getName() << "��(��) " << player->name << "�� �����մϴ�! ";
		player->health -= newMonster->getAttack();
		
		// �÷��̾ ���
		if (player->health <= 0) 
		{
			cout << player->name << " ü��: 0" << endl;
			IsCharacterDead = true;
			break;
		}
		else 
		{
			cout << player->name << " ü��: " << player->health << endl;
		}
	}

	// ���� �¸� -> ����ġ, ��� ȹ�� (+ ���� ������ ȹ��)
	if (!IsCharacterDead) 
	{
		getItemByBattle(player);
	}

	delete newMonster;

	return IsCharacterDead;
}

void GameManager::visitShop(Character* player)
{
	cout << " === ������ �湮�Ͽ����ϴ� === \n";
	player->visitShop();
}

void GameManager::displayInventory(Character* player)
{
	cout << " === ���� �÷��̾ ������ �ִ� ������ === \n";
	for (int i : player->inventory)
	{
		cout << "- " << i << endl;
	}
}

void GameManager::getItemByBattle(Character* player)
{
	GoldToReceive = RandomUtil::getInt(10, 20);	// 10 ~ 20 ��� ���� ȹ��

	player->exp += ExperienceToReceive;
	player->money += GoldToReceive;

	cout << player->name << "�� " << ExperienceToReceive << " EXP�� " << GoldToReceive << " ��带 ȹ���߽��ϴ�. ";
	cout << "���� EXP: " << player->exp << "/100, ���: " << player->money << "\n";
 
	int RandValue = RandomUtil::getInt(1, 100);
	if (RandValue <= ProbabilityToGetItem) 
	{
		cout << "----- ������ ȹ�� -----" << endl;
	}

}
