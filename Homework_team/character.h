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

	int attack(Character* player);


	//about battle 
	//void attack(Character* target);
	void takeDamage(int damage);


	//about equipment
	void addEquipment(Item* item, int ItemID);		 
	void deleteEquipment(Item* item, int ItemID);	

	//about shop
	void buyItem(Item* item);						// �������� �� ���
	void sellItem(Item* item);						// �������� �Ĵ� ���

	//item management
	void addItem(Item* item);						// ��ӵ� �������� �ֿ��� ��, ����� �ڵ����� �ٲ��, �������� �κ��丮��
	void useItem();						// ��� �������� �������� ���

	// ��� �߰�
	void addGold(int amount);

	// �÷��̾� ���� ��ȭ
	void setPlayerState(State state);

	// ���� ���� Getter
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
	Item* weaponEquipment;			// ���� ������
	Item* armourEquipment;			// �� ������
	vector<Item*> potionBag;		// ���� �κ��丮
	vector<Item*> inventory;		// ��� �κ��丮
};