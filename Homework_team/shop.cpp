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
	std::cout << "구매 가능한 아이템:" << std::endl;
	for (size_t i = 0; i < availableItems.size(); i++)
	{
		Item* item = availableItems[i];
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

void Shop::buyItem(int index, Character* player)
{
	if (index - 1 > availableItems.size()) {
		std::cout << "입력한 번호의 아이템은 없습니다.\n";
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
