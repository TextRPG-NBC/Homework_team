#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Character
{
public:
	string name;
	int level = 1;
	int exp = 0;
	int health = 180 + (level*20);
	int attackPower = 25 + (level*5);
	int criticalRate = 0;
	int gold = 0;
	vector<int> inventory;


	Character(const string& name, int level, int exp, int criticalRate, int gold, vector<string> invenroty);
	void displayInfo() const;
	void levelUp();
	void useItem();
};