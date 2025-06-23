#pragma once

#include "item.h"
#include <vector>


class ItemManager
{
private:
	vector<Item*> itemVector;

public:
	void getItemListVector();
	Item* randomItem();
};
