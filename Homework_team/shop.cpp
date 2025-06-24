#include "Shop.h"
#include "ItemManager.h"
#include "Item.h"
#include "character.h"

Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::displayItems()
{
	std::cout << "���� ������ ������:" << std::endl;
	for (size_t i = 0; i < availableItems.size(); i++)
	{
		Item* item = availableItems[i];
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

void Shop::buyItem(int index, Character* player)
{
	if (index - 1 > availableItems.size()) {
		std::cout << "�Է��� ��ȣ�� �������� �����ϴ�.\n";
		return;
	}

	player->buyItem(availableItems[index - 1]);
}

void Shop::sellItem(Item* item, Character* player)
{
	player->sellItem(item);
}

void Shop::fillItem(std::vector<Item*> items)
{
	for (Item* item : items)
	{
		availableItems.push_back(item);
	}
}
