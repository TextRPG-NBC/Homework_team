#include <string>
#include <vector>
#include <iostream>
#include "character.h"
using namespace std;

Character::Character(const string& name, int level, int exp, int criticalRate, int gold, vector<string> invenroty, vector<string> equipment)
	: name(name), level(level), exp(exp), health(180 + (level * 20)), attackPower(25 + (level * 5)), criticalRate(criticalRate), gold(gold), inventory(inventory), equipment(equipment) {}
//레벨에 비례한 체력 공격력


void Character::displayInfo() const { //캐릭터 정보
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << gold << endl;
	if (!equipment.empty()) //장비 목록 출력
	{
		cout << "Inventory: " << endl;
		for (const string& item : inventory)
		{
			cout << "- " << item << endl;
		}
	}
	if (!inventory.empty()) //소모품 목록 출력
	{
		cout << "Inventory: " << endl;
		for (const string& item : inventory)
		{
			cout << "- " << item << endl;
		}
	}
}

void Character::gainExp(int amount) //경험치 획득
{
	exp += amount;
	cout << name << amount << " exp points up!" << endl;

	if (exp > 100)
	{
		levelUp();
	}
}

void Character::levelUp() //레벨업 (gainEXP에 포함되어 있음)
{
	exp -= 100;
	level++;
	health = 180 + (level * 20);
	attackPower = 25 + (level * 5);

	cout << name << " is level up! current level : " << level << endl;
	return;
}

void Character::addEquipment(const string& itemName, int& attackPower_attribute, int& health_attribute, int& critRate_attribute) //장비 추가

{
	equipment.push_back(itemName);
	attackPower += attackPower_attribute;
	health += health_attribute;
	criticalRate += critRate_attribute;
	cout << itemName << " added to equipment." << endl;
}

void Character::unEquipment(const string& itemName, int& attackPower_attribute, int& health_attribute, int& critRate_attribute) //장비 해제
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

void Character::buyItem(const string& itemName, int price) //아이템 구매
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

void Character::sellItem(const string& itemName, int price) // 아이템 판매
{
	gold += price;
	unEquipment(itemName, attackPower, health, criticalRate);
}

void Character::addItem(const string& itemName) //아이템 추가(전투중 습득을 위해 별도 설정함, butItem에 추가되어있음.)
{
		inventory.push_back(itemName);
		cout << itemName << " added to inventory." << endl;
}

void Character::useItem() //아이템 사용
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
