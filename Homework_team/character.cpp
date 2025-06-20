#include <string>
#include <vector>
#include <iostream>
#include "character.h"
using namespace std;

Character::Character(const string& name, int level, int exp, int criticalRate, int money, vector<string> invenroty)
	: name(name), level(level), exp(exp), health(180 + (level * 20)), attackPower(25 + (level * 5)), criticalRate(criticalRate), money(money), inventory(inventory) {
}

void Character::displayInfo() const {
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << money << endl;
	cout << "Inventory: " << endl;
	cout << "------------------------" << endl;
}

void Character::levelUp()
{
}

void Character::useItem()
{
}

void Character::visitShop()
{
}
