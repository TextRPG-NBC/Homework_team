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
	int level; // ����
	int exp; // ����ġ
	int health;	// ü��
	int attackPower; // ���ݷ�
	int criticalRate; // ũ��Ƽ�� Ȯ��
	int gold; // ������
	vector<Item*> equipment; // ��� �κ��丮
	vector<Item*> inventory; // �Һ������ �κ��丮
	
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