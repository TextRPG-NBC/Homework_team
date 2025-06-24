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

	// ��� �߰�
	void addGold(int amount);

	// ���� ���� Getter
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
	string name;					// �̸�
	int level;						// ����
	int exp;						// ����ġ
	int health;						// ü��
	int attackPower;				// ���ݷ�
	int criticalRate;				// ũ��Ƽ�� Ȯ��
	int gold;						// ������
	void addStatus(Item* item);		// ������ ȿ�� �߰�
	void removeStatus(Item* item);	// ������ ȿ�� ����
	State playerState;				// �÷��̾� ����
	vector<Item*> weaponEquipment;	// ���� ���� ���� �κ��丮
	vector<Item*> armourEquipment;	// ���� �� ���� �κ��丮
	vector<Item*> potionBag;		// ���� �κ��丮
	vector<Item*> inventory;		// ��� �κ��丮
};