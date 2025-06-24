#pragma once

#include "item.h"
#include <vector>


class ItemManager
{
private:
	vector<Item*> itemVector;

public:
	vector<Item*> getItemListVector();
	Item* randomItem();
};
