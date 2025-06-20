#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Character {
public:
    string name;
    int level;
    int exp;
    int health;
    int attackPower;
    int criticalRate;
    int money;
    vector<string> inventory;

    Character(const string& name, int level, int exp = 0, int money = 0);

    void displayStatus() const;
    void levelUp();
    void useItem(int index);
    void visitShop();
};
