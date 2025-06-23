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
	// 레벨 10 미만 시 일반 몬스터 소환
	if (player->getLevel() < 10) 
	{
		newMonster = generateMonster(player->getLevel());
	}
	// 레벨 10 달성 시 보스 몬스터 소환
	else
	{
		newMonster = generateBossMonster(player->getLevel());
	}

	assert(newMonster != nullptr);

	// 전투 장면
	while (1) {
		// 플레이어가 몬스터 공격
		cout << player->getName() << "이(가) " << newMonster->getName() << "을 공격합니다! ";
		newMonster->takeDamage(player->getAttackPower());

		// 몬스터 처치
		if (newMonster->getHealth() <= 0) 
		{
			cout << newMonster->getName() << " 처치!" << endl;
			break;
		}
		else 
		{
			cout << newMonster->getName() << " 체력: " << newMonster->getHealth() << endl;
		}

		// 플레이어가 몬스터 공격
		cout << newMonster->getName() << "이(가) " << player->getName() << "을 공격합니다! ";
		player->takeDamage(newMonster->getAttack());
		
		// 플레이어가 사망
		if (player->getHealth() <= 0) 
		{
			cout << player->getName() << " 체력: 0" << endl;
			IsCharacterDead = true;
			break;
		}
		else 
		{
			cout << player->getName() << " 체력: " << player->getHealth() << endl;
		}
	}

	// 전투 승리 -> 경험치, 골드 획득 (+ 랜덤 아이템 획득)
	if (!IsCharacterDead) 
	{
		getItemByBattle(player);
	}

	delete newMonster;

	return IsCharacterDead;
}

void GameManager::visitShop(Character* player)
{
	cout << " === 상점을 방문하였습니다 === \n";
	//TODO : 상점 방문 부분 추가
}

void GameManager::displayInventory(Character* player)
{
	cout << " === 현재 플레이어가 가지고 있는 아이템 === \n";
	// TODO : 인벤토리 출력 기능
}

void GameManager::getItemByBattle(Character* player)
{
	GoldToReceive = RandomUtil::getInt(10, 20);	// 10 ~ 20 골드 랜덤 획득

	player->gainExp(ExperienceToReceive);
	player->addGold(GoldToReceive);

	cout << player->getName() << "가 " << ExperienceToReceive << " EXP와 " << GoldToReceive << " 골드를 획득했습니다. ";
	cout << "현재 EXP: " << player->getExp() << "/100, 골드: " << player->getGold() << "\n";
 
	int RandValue = RandomUtil::getInt(1, 100);
	if (RandValue <= ProbabilityToGetItem) 
	{
		cout << "----- 아이템 획득 -----" << endl;
	}

}
