#include "Shop.h"
#include "ItemManager.h"
#include "Item.h"
#include "character.h"

Shop::Shop()
{
}

Shop::~Shop()
{
	for (Item* item : availableItems) 
	{
		delete item;
	}
}

void Shop::displayItems()
{
	std::cout << "������ ���� ���� ȯ���մϴ�!" << std::endl;
	std::cout << "���� ������ ������:" << std::endl;
	for (size_t i = 0; i < availableItems.size(); i++)
	{
		Item* item = availableItems[i];
		std::cout << i << ". " << item->getItemName(); 
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

void Shop::buyItem(int index, Character* player)
{
	if (index - 1 > availableItems.size()) {
		std::cout << "�Է��� ��ȣ�� �������� �����ϴ�.\n";
		return;
	}

	
	// TODO
	// 1. ĳ���� �κ��丮�� �߰�
	// 2. ������ ���ſ� ���� ���� ���

	std::cout << availableItems[index - 1]->getItemName() << "�� �����߽��ϴ�!\n";
}

void Shop::sellItem(int index, Character* player)
{
	// TODO
	// 1. ĳ���� �κ��丮 ���� �� �Ǹ�
}

void Shop::fillItem(std::vector<Item*> items)
{
	for (Item* item : items)
	{
		availableItems.push_back(new Item(item->getItemName(), item->getItemID()
				, item->getPrice(), item->getAttackPower(), item->getHealth(), item->getCritRate()));
	}
}
