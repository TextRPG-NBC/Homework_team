#pragma once

#include "CommonInclude.h"

class Character;

struct Item {
	std::string name;
	std::string increateStat;
	int amountOfIncreateStat;
	int price;
};

class Shop
{
public:
	Shop();
	void displayItems();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);

private:
	std::vector<Item> availableItems;
};

