#pragma once

#include <string>
#include <iostream>

using namespace std;

class Item
{
public:
	string itemName;
	int price;
	int attackPower_attribute;
	int health_attribute;
	int critRate_attribute;

	Item(string name, int price, int attackPower, int health, int critRate)
		: itemName(name), price(price), attackPower_attribute(attackPower), health_attribute(health), critRate_attribute(critRate) {
	}

	virtual ~Item() {};
};

class equpItem : public Item
{

};