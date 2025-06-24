#pragma once

#include "CommonInclude.h"

class Item;

class ItemManager
{
public:
	ItemManager();
	~ItemManager();

	std::vector<Item*> getItemListVector();
	Item* getRandomItem();

private:
	std::vector<Item*> itemVector;
};
