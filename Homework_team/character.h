#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Character {
public:
	string name;
	int level = 1;
	int exp = 0;
	int health = 0;
	int attackPower = 0;
	int money = 0;

	Character(const string& name, int level, int exp = 0, int money = 0)
		: name(name), level(level), exp(exp), health(180 + (level * 20)), attackPower(25 + (level * 5)), money(money) {
	}
{
};

