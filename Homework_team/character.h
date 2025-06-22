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
	int level; // ����
	int exp; // ����ġ
	int health;	// ü��
	int attackPower; // ���ݷ�
	int criticalRate; // ũ��Ƽ�� Ȯ��
	int gold; // ������
	vector<string> equipment; // ��� �κ��丮
	vector<string> inventory; // �Һ������ �κ��丮
	

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