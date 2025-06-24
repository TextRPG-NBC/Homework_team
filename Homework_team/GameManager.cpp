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
	// ������ ���
	player->useItem();

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
		player->setPlayerState(Character::State::CLEAR);
	}

	assert(newMonster != nullptr);

	// ���� ���
	while (1) {
		// �÷��̾ ���� ����
		cout << player->getName() << "��(��) " << newMonster->getName() << "�� �����մϴ�! ";
		newMonster->takeDamage(player->attack(player));

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
			break;
		}
		else 
		{
			cout << player->getName() << " ü��: " << player->getHealth() << endl;
		}
	}
	cout << endl;

	// ���� �¸� -> ����ġ, ��� ȹ�� (+ ���� ������ ȹ��)
	if (player->getPlayerState() == Character::State::ALIVE) 
	{
		getItemByBattle(newMonster->dropItem());
	}

	delete newMonster;
}

void GameManager::visitShop()
{
	cout << " ===== ������ ���� ���� ȯ���մϴ�! ===== \n";
	cout << "   1. ����\n";
	cout << "   2. �Ǹ�\n";
	cout << "   3. �Ѿ��\n";
	cout << " ====================================== \n";
	cout << " �������� �Ͻ� ���� ����ּ��� (1:����, 2:�Ǹ�): ";
	
	int selectNum;
	cin >> selectNum;

	if (selectNum == 1) 
	{	
		// ���� ������ ������ ���
		shopManager->displayItems();

		// ĳ���� ���� ��� ���
		cout << " ���� ���: " << player->getGold() << "\n";

		// ������ ������ ��ȣ ����
		int BuyItemNumber = 0;
		cout << "������ ������ ��ȣ�� �����ϼ��� (0:�Ѿ��): ";
		cin >> BuyItemNumber;

		if (BuyItemNumber != 0)
		{
			shopManager->buyItem(BuyItemNumber, player);
		}
	}
	else if (selectNum == 2)
	{
		// ĳ���Ͱ� ������ �κ��丮 ���
		vector<Item*> items = displayInventory();

		if (items.size() > 0)
		{
			// �Ǹ��� ������ ��ȣ ����
			int SellItemNumber = 0;
			cout << "�Ǹ��� ������ ��ȣ�� �����ϼ��� (0:�Ѿ��): ";
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
	cout << " ===== ���� �÷��̾ ������ �ִ� ������ ===== \n";
	vector<Item*> items = player->inventoryInfo();

	if (items.size() > 0)
	{
		for (size_t i = 0; i < items.size(); i++)
		{
			Item* item = items[i];
			std::cout << i + 1 << ". " << item->getItemName();
			if (item->getAttackPower() > 0)
			{
				std::cout << " (���ݷ� + " << item->getAttackPower() << ")";
			}
			else if (item->getCritRate() > 0)
			{
				std::cout << " (ũ��Ƽ�� Ȯ�� + " << item->getCritRate() << ")";
			}
			else if (item->getHealth() > 0)
			{
				std::cout << " (ü�� + " << item->getHealth() << ")";
			}

			std::cout << ": " << item->getPrice() << " ���\n";
		}
	}
	else
	{
		std::cout << "        - ���� ���� �������� �����ϴ� -\n";
	}

	std::cout << " ==============================================\n\n ";

	return items;
}

void GameManager::run()
{
	getPlayerName();

	// �÷��̾� ���� ���
	player->displayInfo();
	system("pause");

	while (1) {
		system("cls");
		
		// �����ϱ�
		battle();

		// �÷��̾� ���� ���
		player->displayInfo();

		// �÷��̾� �κ��丮 ���
		displayInventory();

		// 1. ���� �¸� -> ���� �ý��� -> ���� ����
		if (player->getPlayerState() == Character::State::ALIVE)
		{
			// ���� �ý���
			string IsShopping;
			cout << "������ �湮�Ͻðڽ��ϱ�? (Y/N): ";
			cin >> IsShopping;

			if (IsShopping == "Y" || IsShopping == "y")
			{
				visitShop();
			}

			system("pause");
		}
		// 2. ĳ���� ��� -> ���� ����
		else if (player->getPlayerState() == Character::State::DEAD)
		{
			cout << player->getName() << "��(��) ����߽��ϴ�. ���� ����!\n";
			break;
		}
		// 3. ���� ���� óġ
		else if (player->getPlayerState() == Character::State::CLEAR)
		{
			cout << "�����մϴ�! ���� ���͸� óġ�ϰ� ������ Ŭ�����߽��ϴ�!\n";
			break;
		}
	}

}

void GameManager::getItemByBattle(Item* item)
{
	GoldToReceive = RandomUtil::getInt(10, 20);	// 10 ~ 20 ��� ���� ȹ��

	player->addExp(ExperienceToReceive);
	player->addGold(GoldToReceive);

	cout << player->getName() << "�� " << ExperienceToReceive << " EXP�� " << GoldToReceive << " ��带 ȹ���߽��ϴ�. ";
	cout << "���� EXP: " << player->getExp() << "/100, ���: " << player->getGold() << "\n";
 
	int RandValue = RandomUtil::getInt(1, 100);
	if (RandValue <= ProbabilityToGetItem) 
	{
		player->addItem(item);
		cout << player->getName() << "��(��) " << item->getItemName() << "�� ȹ���߽��ϴ�!!!" << endl;
	}
}

void GameManager::getPlayerName()
{
	// ĳ���� ���� (�̸� �Է�)
	string PlayerName;
	cout << "ĳ���� �̸��� �Է��ϼ���: ";
	getline(cin, PlayerName);

	do {
		if (PlayerName != "")	// �Է� ��ȿ�� �˻�
			break;
		cin.ignore();
		cout << "ĳ���� �̸��� ���Է��ϼ���: ";
	} while (getline(cin, PlayerName));

	player = new Character(PlayerName);
	system("cls");

	cout << "===== ĳ���� ���� �Ϸ� =====\n";
}
