#include <string>
#include <vector>
#include <iostream>
#include "character.h"
#include "item.h"

using namespace std;


Character::Character(const string& name, int level, int exp, int criticalRate, int gold, vector<Item*> equipemnt, vector<string> invenroty)
	: name(name), level(level), exp(exp), health(180 + (level * 20)), attackPower(25 + (level * 5)), criticalRate(criticalRate), gold(gold), inventory(inventory), equipment(equipment) {} //������ ����� ü�� ���ݷ�


	void Character::displayInfo() const { //ĳ���� ����
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << exp << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
    cout << "Critical Rate: " << criticalRate << "%" << endl;
    cout << "Have money : " << gold << endl;

	if (inventory.empty()) {
		cout << "Inventory is empty!" << endl; //�Ҹ�ǰ�� ���� ���
	} else {
		for (Item* item : inventory) {
			cout << "Inventory Item: " << item->itemName << endl; //������ ��� ���
		}
	}
	
	if (equipment.empty()) {
		cout << "Inventory is empty!" << endl; //�Ҹ�ǰ�� ���� ���
	}
	else {
		for (Item* item : equipment) {
			cout << "Inventory Item: " << item->itemName << endl; //������ ��� ���
		}
	}
}


void Character::gainExp(int amount) //����ġ ȹ��
{
	exp += amount;
	cout << name << amount << " exp points up!" << endl;
}

void Character::levelUp() //������
{
	exp -= 100;
	level++;
	health = 180 + (level * 20);
	attackPower = 25 + (level * 5);

	cout << name << " is level up! current level : " << level << endl;
	return;
}

void Character::addEquipment(Item* item)
{
	equipment.push_back(item);
	attackPower += item->attackPower_attribute;
	health += item->health_attribute;
	criticalRate += item->critRate_attribute;
	cout << item->itemName << " added to equipment." << endl;
}


void Character::unEquipment(Item* item) //��� ����
{
	for (auto it = equipment.begin(); it != equipment.end(); ++it)
	{
		if (*it == item) //�������� ��� �ִ��� Ȯ��
		{
			equipment.erase(it);
			attackPower -= item->attackPower_attribute;
			health -= item->health_attribute;
			criticalRate -= item->critRate_attribute;
			cout << item->itemName << " removed from equipment." << endl;
			return;
		}
	}
}

void Character::buyItem(Item* item) //������ ����
{
	if (gold < item->price)
	{
		cout << "Not enough gold to buy " << item->itemName << "." << endl;
		return;
	}
	else
	{
		gold -= item->price;
		cout << item->itemName << " bought for " << item->price << " gold." << endl;
	}
}

void Character::addItem(Item* item) //������ �߰�
{
	inventory.push_back(item);
	cout << item->itemName << " added to inventory." << endl;
}

void Character::sellItem(Item* item) // ������ �Ǹ�
{
	gold += item->price;
	unEquipment(item);
}


void Character::useItem(Item* item) //������ ���
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
		//��� �� ���� ��� �߰� �ʿ�

		
	}
}

