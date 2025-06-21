#include "Shop.h"

#include "character.h"

Shop::Shop()
{
	// �ʱ� ���� ������ �߰�
	availableItems.push_back({ "Healing Potion", "ü��", 50, 100});
	availableItems.push_back({ "Attack Boost", "���ݷ�", 20, 150});
	availableItems.push_back({ "Weapon", "���ݷ�", 30, 300 });
	availableItems.push_back({ "Armor", "ü��", 40, 300 });
}

void Shop::displayItems()
{
	std::cout << "������ ���� ���� ȯ���մϴ�!" << std::endl;
	std::cout << "���� ������ ������:" << std::endl;
	for (size_t i = 0; i < availableItems.size(); i++)
	{
		Item item = availableItems[i];
		std::cout << i << ". " << item.name << " (" << item.increateStat;
		std::cout << " + " << item.amountOfIncreateStat << "): " << item.price << " ���\n";
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

	std::cout << availableItems[index - 1].name << "�� �����߽��ϴ�!\n";
	availableItems.erase(availableItems.begin() + index - 1);
}

void Shop::sellItem(int index, Character* player)
{
	// TODO
	// 1. ĳ���� �κ��丮 ���� �� �Ǹ�
}
