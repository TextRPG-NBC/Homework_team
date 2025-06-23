#pragma once

#include "CommonInclude.h"
#include <string>
#include <iostream>

using namespace std;

class Item
{
public:
	string itemName;
	int itemID;			//0�� ����, 1�� ��, 2�� ����
	int price;
	int attackPower_attribute;
	int health_attribute;
	int critRate_attribute;

	Item(string name, int itemID, int price, int attackPower, int health, int critRate)
		: itemName(name)
		, itemID(0)
		, price(price)
		, attackPower_attribute(attackPower)
		, health_attribute(health)
		, critRate_attribute(critRate) {}

	virtual ~Item() {};
};

class equpItem : public Item
{

};