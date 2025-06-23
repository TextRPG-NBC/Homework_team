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
	if (player->getLevel() < 10) 
	{
		newMonster = generateMonster(player->getLevel());
	}
	// ���� 10 �޼� �� ���� ���� ��ȯ
	else
	{
		newMonster = generateBossMonster(player->getLevel());
	}

	assert(newMonster != nullptr);

	// ���� ���
	while (1) {
		// �÷��̾ ���� ����
		cout << player->getName() << "��(��) " << newMonster->getName() << "�� �����մϴ�! ";
		newMonster->takeDamage(player->getAttackPower());

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
		cout << newMonster->getName() << "��(��) " << player->getName() << "�� �����մϴ�! ";
		player->takeDamage(newMonster->getAttack());
		
		// �÷��̾ ���
		if (player->getHealth() <= 0) 
		{
			cout << player->getName() << " ü��: 0" << endl;
			IsCharacterDead = true;
			break;
		}
		else 
		{
			cout << player->getName() << " ü��: " << player->getHealth() << endl;
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
	//TODO : ���� �湮 �κ� �߰�
}

void GameManager::displayInventory(Character* player)
{
	cout << " === ���� �÷��̾ ������ �ִ� ������ === \n";
	// TODO : �κ��丮 ��� ���
}

void GameManager::getItemByBattle(Character* player)
{
	GoldToReceive = RandomUtil::getInt(10, 20);	// 10 ~ 20 ��� ���� ȹ��

	player->gainExp(ExperienceToReceive);
	player->addGold(GoldToReceive);

	cout << player->getName() << "�� " << ExperienceToReceive << " EXP�� " << GoldToReceive << " ��带 ȹ���߽��ϴ�. ";
	cout << "���� EXP: " << player->getExp() << "/100, ���: " << player->getGold() << "\n";
 
	int RandValue = RandomUtil::getInt(1, 100);
	if (RandValue <= ProbabilityToGetItem) 
	{
		cout << "----- ������ ȹ�� -----" << endl;
	}

}
