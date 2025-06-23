#pragma once

#include "CommonInclude.h"

using namespace std;

class Item;

class Character
{
	enum State
	{
		ALIVE,
		DEAD,
		CLEAR,
		END
	};

public:
	Character(const string& name);

	//about character status
	void displayInfo() const;
	void gainExp(int amount); 
	void levelUp();

	//about battle 
	void takeDamage(int damage);

	//about equipment
	void addEquipment(Item* item);
	void unEquipment(Item* item);

	//about shop
	void buyItem(Item* item);
	void sellItem(Item* item);

	//item management
	void addItem(Item* item);
	void useItem(Item* item);

	// 스탯 추가
	void addGold(int amount);

	// 스탯 정보 Getter
	string getName() 			 const { return name; }
	int getLevel() 				 const { return level; }
	int getExp() 				 const { return exp; }
	int getHealth() 			 const { return health; }
	int getAttackPower() 		 const { return attackPower; }
	int getCriticalRate() 		 const { return criticalRate; }
	int getGold() 				 const { return gold; }
	int getPlayerState() 		 const { return playerState; }
	vector<Item*> getEquipment()	   { return equipment; }
	vector<Item*> getInventory()	   { return inventory; }

private:
	string name;				// 이름
	int level;					// 레벨
	int exp;					// 경험치
	int health;					// 체력
	int attackPower;			// 공격력
	int criticalRate;			// 크리티컬 확률
	int gold;					// 소지금
	State playerState;			// 플레이어 상태
	vector<Item*> equipment;	// 장비 인벤토리
	vector<Item*> inventory;	// 소비아이템 인벤토리
};