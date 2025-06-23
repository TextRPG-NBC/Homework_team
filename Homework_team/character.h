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
	void addStatus(Item* item);
	void removeStatus(Item* item);

	//about battle 
	void attack(Character* target);
	void takeDamage(int damage);

	//about equipment
	void addEquipment(Item* item, int positon);
	void deleteEquipment(Item* item, int position);

	//about shop
	void buyItem(Item* item);
	void sellItem(Item* item);

	//item management
	void getItem(Item* item);
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
	vector<Item*> getEquipment()	   { return equipment; }
	vector<Item*> getPotionBag()	   { return PotionBag; }
	vector<Item*> getInventory()	   { return inventory; }

private:
	string name;				// �̸�
	int level;					// ����
	int exp;					// ����ġ
	int health;					// ü��
	int attackPower;			// ���ݷ�
	int criticalRate;			// ũ��Ƽ�� Ȯ��
	int gold;					// ������
	State playerState;			// �÷��̾� ����
	vector<Item*> equipment;	// ���� ���� �κ��丮
	vector<Item*> PotionBag;	// ���� �κ��丮
	vector<Item*> inventory;	// ��� �κ��丮
};