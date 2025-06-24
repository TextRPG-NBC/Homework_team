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
	std::cout << "상점에 오신 것을 환영합니다!" << std::endl;
	std::cout << "구매 가능한 아이템:" << std::endl;
	for (size_t i = 0; i < availableItems.size(); i++)
	{
		Item* item = availableItems[i];
		std::cout << i << ". " << item->getItemName(); 
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

	
	// TODO
	// 1. 캐릭터 인벤토리에 추가
	// 2. 아이템 구매에 따른 스탯 상승

	std::cout << availableItems[index - 1]->getItemName() << "을 구매했습니다!\n";
}

void Shop::sellItem(int index, Character* player)
{
	// TODO
	// 1. 캐릭터 인벤토리 구현 후 판매
}

void Shop::fillItem(std::vector<Item*> items)
{
	for (Item* item : items)
	{
		availableItems.push_back(new Item(item->getItemName(), item->getItemID()
				, item->getPrice(), item->getAttackPower(), item->getHealth(), item->getCritRate()));
	}
}
