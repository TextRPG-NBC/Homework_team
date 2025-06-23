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
		DEAD,
		CLEAR,
		END
		};

public:
	string name;
	int level; // 레벨
	int exp; // 경험치
	int health;	// 체력
	int attackPower; // 공격력
	int criticalRate; // 크리티컬 확률
	int gold; // 소지금
	vector<Item*> equipment; // 장비 인벤토리
	vector<Item*> inventory; // 소비아이템 인벤토리
	
	Character(const string& name, int level, int exp, int criticalRate, int gold, vector<Item*> equipemnt, vector<string> invenroty);

	//about character status
	void displayInfo() const;
	void gainExp(int amount); 
	void levelUp();

	//about equipment
	void addEquipment(Item* item);
	void unEquipment(Item* item);

	//about shop
	void buyItem(Item* item);
	void sellItem(Item* item);

	//item management
	void addItem(Item* item);
	void useItem(Item* item);
};