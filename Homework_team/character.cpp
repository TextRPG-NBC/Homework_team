#include <iostream>
#include "character.h"

using namespace std;

Character::Character(const string& name, int level, int exp, int money)
    : name(name), level(level), exp(exp),
    health(180 + (level * 20)),
    attackPower(25 + (level * 5)),
    criticalRate(0),  // 필요하면 초기화
    money(money) {
}

void Character::displayStatus() const {
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << exp << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
    cout << "Critical Rate: " << criticalRate << "%" << endl;
    cout << "Money: " << money << endl;
    cout << "Inventory: ";
    for (const auto& item : inventory) {
        cout << item << " ";
    }
    cout << endl;
}

void Character::levelUp() {
    level++;
    health = 180 + (level * 20);
    attackPower = 25 + (level * 5);
    cout << name << " leveled up to " << level << "!" << endl;
}

void Character::useItem(int index) {
    if (index >= 0 && index < inventory.size()) {
        cout << name << " used " << inventory[index] << "." << endl;
        inventory.erase(inventory.begin() + index);
    }
    else {
        cout << "Invalid item index." << endl;
    }
}

void Character::visitShop() {
    cout << "Visiting the shop..." << endl;
}
