#pragma once

#include "CommonInclude.h"

using namespace std;

// Change 'class Item;' to 'struct Item;' to match the definition in shop.h
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

	int attack(Monster* target);


	//about battle 
	//void attack(Character* target);
	void takeDamage(int damage);


	//about equipment
	void addEquipment(Item* item, int positon);
	void deleteEquipment(Item* item, int position);

	/*about shop
	void buyItem(Item* item);
	void sellItem(Item* item);
	*/

	//item management
	void addItem(Item* item);
	void useItem(Item* item);

	// 골드 추가
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
	vector<Item*> getWeaponEquipment() { return weaponEquipment; }
	vector<Item*> getArmourEquipment() { return armourEquipment; }
	vector<Item*> getPotionBag()	   { return potionBag; }
	vector<Item*> getInventory()	   { return inventory; }

private:
	string name;					// 이름
	int level;						// 레벨
	int exp;						// 경험치
	int health;						// 체력
	int attackPower;				// 공격력
	int criticalRate;				// 크리티컬 확률
	int gold;						// 소지금
	void addStatus(Item* item);		// 아이템 효과 추가
	void removeStatus(Item* item);	// 아이템 효과 제거
	State playerState;				// 플레이어 상태
	vector<Item*> weaponEquipment;	// 현재 무기 장착 인벤토리
	vector<Item*> armourEquipment;	// 현재 방어구 장착 인벤토리
	vector<Item*> potionBag;		// 포션 인벤토리
	vector<Item*> inventory;		// 장비 인벤토리
};