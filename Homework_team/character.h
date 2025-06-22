#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Character
{
	enum state
		{
		ALIVE,
		DEAD
		};
public:
	string name;
	int level; // 레벨
	int exp; // 경험치
	int health;	// 체력
	int attackPower; // 공격력
	int criticalRate; // 크리티컬 확률
	int gold; // 소지금
	vector<string> equipment; // 장비 인벤토리
	vector<string> inventory; // 소비아이템 인벤토리
	

	Character(const string& name, int level, int exp, int criticalRate, int gold, vector<string> equipemnt, vector<string> invenroty);

	//about character status
	void displayInfo() const;
	void gainExp(int amount); 
	void levelUp();

	//about equipment
	void addEquipment(const string& itemName, int& attackPower_attribute, int& health_attribute, int& critRate_attribute);
	void unEquipment(const string& itemName, int& attackPower_attribute, int& health_attribute, int& critRate_attribute);

	//about shop
	void buyItem(const string& itemName, int price);
	void sellItem(const string& itemName, int price);

	//item management
	void addItem(const string& itemName);
	void useItem();
};