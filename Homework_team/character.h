#pragma once

#include "CommonInclude.h"

using namespace std;

// Change 'class Item;' to 'struct Item;' to match the definition in shop.h
class Item;
class Monster;

class Character
{
public:
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
	vector<Item*> inventoryInfo();
	void addExp(int amount);

	int attack(Monster* target);


	//about battle 
	//void attack(Character* target);
	void takeDamage(int damage);


	//about equipment
	void addEquipment(Item* item, int ItemID);		 
	void deleteEquipment(Item* item, int ItemID);	

	//about shop
	void buyItem(Item* item);						// 아이템을 산 경우
	void sellItem(Item* item);						// 아이템을 파는 경우

	//item management
	void addItem(Item* item);						// 드롭된 아이템을 주웠을 때, 장비라면 자동으로 바뀌고, 나머지는 인벤토리로
	void useItem();						// 사용 아이템을 랜덤으로 사용

	// 골드 추가
	void addGold(int amount);

	// 플레이어 상태 변화
	void setPlayerState(State state);

	// 스탯 정보 Getter
	string getName() 			 const	{ return name; }
	int getLevel() 				 const	{ return level; }
	int getExp() 				 const	{ return exp; }
	int getHealth() 			 const	{ return health; }
	int getAttackPower() 		 const	{ return attackPower; }
	int getCriticalRate() 		 const	{ return criticalRate; }
	int getGold() 				 const	{ return gold; }
	State getPlayerState() 		 const	{ return playerState; }
	Item* getWeaponEquipment()			{ return weaponEquipment; }
	Item* getArmourEquipment()			{ return armourEquipment; }
	vector<Item*> getPotionBag()		{ return potionBag; }
	vector<Item*> getInventory()		{ return inventory; }

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
	Item* weaponEquipment;			// 무기 포인터
	Item* armourEquipment;			// 방어구 포인터
	vector<Item*> potionBag;		// 포션 인벤토리
	vector<Item*> inventory;		// 장비 인벤토리
};