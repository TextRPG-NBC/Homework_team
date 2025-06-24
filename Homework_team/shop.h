#pragma once

#include "CommonInclude.h"

class Item;
class Character;

class Shop
{
public:
	Shop();
	~Shop();
	void displayItems();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);
	void fillItem(std::vector<Item*> items);

private:
	std::vector<Item*> availableItems;
};

