#include "Shop.h"

#include "character.h"

Shop::Shop()
{
	// 초기 상점 아이템 추가
	availableItems.push_back({ "Healing Potion", "체력", 50, 100});
	availableItems.push_back({ "Attack Boost", "공격력", 20, 150});
	availableItems.push_back({ "Weapon", "공격력", 30, 300 });
	availableItems.push_back({ "Armor", "체력", 40, 300 });
}

void Shop::displayItems()
{
	std::cout << "상점에 오신 것을 환영합니다!" << std::endl;
	std::cout << "구매 가능한 아이템:" << std::endl;
	for (size_t i = 0; i < availableItems.size(); i++)
	{
		Item item = availableItems[i];
		std::cout << i << ". " << item.name << " (" << item.increateStat;
		std::cout << " + " << item.amountOfIncreateStat << "): " << item.price << " 골드\n";
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

	std::cout << availableItems[index - 1].name << "을 구매했습니다!\n";
	availableItems.erase(availableItems.begin() + index - 1);
}

void Shop::sellItem(int index, Character* player)
{
	// TODO
	// 1. 캐릭터 인벤토리 구현 후 판매
}
