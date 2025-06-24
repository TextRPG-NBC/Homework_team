#include "GameManager.h"
#include "Monster.h"
#include "MonsterTypes.h"
#include "character.h"
#include "ItemManager.h"
#include "Shop.h"

GameManager::GameManager()
	: ExperienceToReceive(50)
	, GoldToReceive(0)
	, ProbabilityToGetItem(30)
	, player(nullptr)
{
	itemManager = new ItemManager();
	shopManager = new Shop();
	shopManager->fillItem(itemManager->getItemListVector());
}

GameManager::~GameManager()
{
	delete player;
	delete shopManager;
	delete itemManager;
}

Monster* GameManager::generateMonster(int level)
{
	int NumberOfMonster = 3;
	int RandomValue = RandomUtil::getInt(0, NumberOfMonster - 1);

	Monster* newMonster = nullptr;
	Item* item = itemManager->getRandomItem();

	if (RandomValue == 0)
	{
		newMonster = new Goblin(level, item);
	}
	else if (RandomValue == 1)
	{
		newMonster = new Orc(level, item);
	}
	else if (RandomValue == 2)
	{
		newMonster = new Troll(level, item);
	}
	newMonster->displayMonster();

	return newMonster;
}

BossMonster* GameManager::generateBossMonster(int level)
{
	Item* item = itemManager->getRandomItem();

	BossMonster* newBossMonster = new BossMonster(level, item);
	newBossMonster->displayMonster();

	return newBossMonster;
}

void GameManager::battle()
{
	// 아이템 사용
	player->useItem();

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
		player->setPlayerState(Character::State::CLEAR);
	}

	assert(newMonster != nullptr);

	// 전투 장면
	while (1) {
		// 플레이어가 몬스터 공격
		cout << player->getName() << "이(가) " << newMonster->getName() << "을 공격합니다! ";
		newMonster->takeDamage(player->attack(player));

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
			break;
		}
		else 
		{
			cout << player->getName() << " 체력: " << player->getHealth() << endl;
		}
	}
	cout << endl;

	// 전투 승리 -> 경험치, 골드 획득 (+ 랜덤 아이템 획득)
	if (player->getPlayerState() == Character::State::ALIVE) 
	{
		getItemByBattle(newMonster->dropItem());
	}

	delete newMonster;
}

void GameManager::visitShop()
{
	cout << " ===== 상점에 오신 것을 환영합니다! ===== \n";
	cout << "   1. 구매\n";
	cout << "   2. 판매\n";
	cout << "   3. 넘어가기\n";
	cout << " ====================================== \n";
	cout << " 상점에서 하실 일을 골라주세요 (1:구매, 2:판매): ";
	
	int selectNum;
	cin >> selectNum;

	if (selectNum == 1) 
	{	
		// 구매 가능한 아이템 출력
		shopManager->displayItems();

		// 캐릭터 보유 골드 출력
		cout << " 보유 골드: " << player->getGold() << "\n";

		// 구매할 아이템 번호 선택
		int BuyItemNumber = 0;
		cout << "구매할 아이템 번호를 선택하세요 (0:넘어가기): ";
		cin >> BuyItemNumber;

		if (BuyItemNumber != 0)
		{
			shopManager->buyItem(BuyItemNumber, player);
		}
	}
	else if (selectNum == 2)
	{
		// 캐릭터가 보유한 인벤토리 출력
		vector<Item*> items = displayInventory();

		if (items.size() > 0)
		{
			// 판매할 아이템 번호 선택
			int SellItemNumber = 0;
			cout << "판매할 아이템 번호를 선택하세요 (0:넘어가기): ";
			cin >> SellItemNumber;

			if (SellItemNumber != 0 && SellItemNumber <= items.size())
			{
				player->sellItem(items[SellItemNumber - 1]);
			}
		}
	}

}

vector<Item*> GameManager::displayInventory()
{
	cout << " ===== 현재 플레이어가 가지고 있는 아이템 ===== \n";
	vector<Item*> items = player->inventoryInfo();

	if (items.size() > 0)
	{
		for (size_t i = 0; i < items.size(); i++)
		{
			Item* item = items[i];
			std::cout << i + 1 << ". " << item->getItemName();
			if (item->getAttackPower() > 0)
			{
				std::cout << " (공격력 + " << item->getAttackPower() << ")";
			}
			else if (item->getCritRate() > 0)
			{
				std::cout << " (크리티컬 확률 + " << item->getCritRate() << ")";
			}
			else if (item->getHealth() > 0)
			{
				std::cout << " (체력 + " << item->getHealth() << ")";
			}

			std::cout << ": " << item->getPrice() << " 골드\n";
		}
	}
	else
	{
		std::cout << "        - 현재 가진 아이템이 없습니다 -\n";
	}

	std::cout << " ==============================================\n\n ";

	return items;
}

void GameManager::run()
{
	getPlayerName();

	// 플레이어 스탯 출력
	player->displayInfo();
	system("pause");

	while (1) {
		system("cls");
		
		// 전투하기
		battle();

		// 플레이어 스탯 출력
		player->displayInfo();

		// 플레이어 인벤토리 출력
		displayInventory();

		// 1. 전투 승리 -> 상점 시스템 -> 다음 전투
		if (player->getPlayerState() == Character::State::ALIVE)
		{
			// 상점 시스템
			string IsShopping;
			cout << "상점을 방문하시겠습니까? (Y/N): ";
			cin >> IsShopping;

			if (IsShopping == "Y" || IsShopping == "y")
			{
				visitShop();
			}

			system("pause");
		}
		// 2. 캐릭터 사망 -> 게임 종료
		else if (player->getPlayerState() == Character::State::DEAD)
		{
			cout << player->getName() << "이(가) 사망했습니다. 게임 오버!\n";
			break;
		}
		// 3. 보스 몬스터 처치
		else if (player->getPlayerState() == Character::State::CLEAR)
		{
			cout << "축하합니다! 보스 몬스터를 처치하고 게임을 클리어했습니다!\n";
			break;
		}
	}

}

void GameManager::getItemByBattle(Item* item)
{
	GoldToReceive = RandomUtil::getInt(10, 20);	// 10 ~ 20 골드 랜덤 획득

	player->addExp(ExperienceToReceive);
	player->addGold(GoldToReceive);

	cout << player->getName() << "가 " << ExperienceToReceive << " EXP와 " << GoldToReceive << " 골드를 획득했습니다. ";
	cout << "현재 EXP: " << player->getExp() << "/100, 골드: " << player->getGold() << "\n";
 
	int RandValue = RandomUtil::getInt(1, 100);
	if (RandValue <= ProbabilityToGetItem) 
	{
		player->addItem(item);
		cout << player->getName() << "이(가) " << item->getItemName() << "을 획득했습니다!!!" << endl;
	}
}

void GameManager::getPlayerName()
{
	// 캐릭터 생성 (이름 입력)
	string PlayerName;
	cout << "캐릭터 이름을 입력하세요: ";
	getline(cin, PlayerName);

	do {
		if (PlayerName != "")	// 입력 유효성 검사
			break;
		cin.ignore();
		cout << "캐릭터 이름을 재입력하세요: ";
	} while (getline(cin, PlayerName));

	player = new Character(PlayerName);
	system("cls");

	cout << "===== 캐릭터 생성 완료 =====\n";
}
