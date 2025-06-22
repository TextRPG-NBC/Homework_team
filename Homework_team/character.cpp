#include <string>
#include <vector>
#include <iostream>
#include "character.h"
using namespace std;

Character::Character(const string& name, int level, int exp, int criticalRate, int gold, vector<string> invenroty, vector<string> equipment)
	: name(name), level(level), exp(exp), health(180 + (level * 20)), attackPower(25 + (level * 5)), criticalRate(criticalRate), gold(gold), inventory(inventory), equipment(equipment) {}
//������ ����� ü�� ���ݷ�


void Character::displayInfo() const { //ĳ���� ����
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << gold << endl;
	if (!equipment.empty()) //��� ��� ���
	{
		cout << "Inventory: " << endl;
		for (const string& item : inventory)
		{
			cout << "- " << item << endl;
		}
	}
	if (!inventory.empty()) //�Ҹ�ǰ ��� ���
	{
		cout << "Inventory: " << endl;
		for (const string& item : inventory)
		{
			cout << "- " << item << endl;
		}
	}
}

void Character::gainExp(int amount) //����ġ ȹ��
{
	exp += amount;
	cout << name << amount << " exp points up!" << endl;

	if (exp > 100)
	{
		levelUp();
	}
}

void Character::levelUp() //������ (gainEXP�� ���ԵǾ� ����)
{
	exp -= 100;
	level++;
	health = 180 + (level * 20);
	attackPower = 25 + (level * 5);

	cout << name << " is level up! current level : " << level << endl;
	return;
}

void Character::addEquipment(const string& itemName, int& attackPower_attribute, int& health_attribute, int& critRate_attribute) //��� �߰�

{
	equipment.push_back(itemName);
	attackPower += attackPower_attribute;
	health += health_attribute;
	criticalRate += critRate_attribute;
	cout << itemName << " added to equipment." << endl;
}

void Character::unEquipment(const string& itemName, int& attackPower_attribute, int& health_attribute, int& critRate_attribute) //��� ����
{
	for (auto it = equipment.begin(); it != equipment.end(); ++it)
	{
		if (*it == itemName)
		{
			equipment.erase(it);
			attackPower -= attackPower_attribute;
			health -= health_attribute;
			criticalRate -= critRate_attribute;
			cout << itemName << " removed from equipment." << endl;
			return;
		}
	}
}

void Character::buyItem(const string& itemName, int price) //������ ����
{
	if (gold < price)
	{
		cout << "Not enough gold to buy " << itemName << "." << endl;
		return;
	}
	else
	{
		gold -= price;
		addItem(itemName);
		cout << itemName << " bought for " << price << " gold." << endl;
	}
}

void Character::sellItem(const string& itemName, int price) // ������ �Ǹ�
{
	gold += price;
	unEquipment(itemName, attackPower, health, criticalRate);
}

void Character::addItem(const string& itemName) //������ �߰�(������ ������ ���� ���� ������, butItem�� �߰��Ǿ�����.)
{
		inventory.push_back(itemName);
		cout << itemName << " added to inventory." << endl;
}

void Character::useItem() //������ ���
{
	if (inventory.empty())
	{
		cout << "Inventory is empty!" << endl;
		return;
	}
	else
	{
		for (int i = 0; i <= inventory.size(); i++)
		{
			cout << i << ". " << inventory[i] << endl;
		}
		int selectItem;
		cout << "Select item to use: ";
		cin >> selectItem;
	}
}
