#pragma once
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string itemName;
    int itemID; //0:公扁, 1 : 规绢备, 2 : 器记
    int attackPower_attribute;
    int health_attribute;
    int critRate_attribute;
    int price;

public:
    Item(string name, int itemID, int price, int attackPower, int health, int critRate)
        : itemName(name)
        , itemID(0)
        , price(price)
        , attackPower_attribute(attackPower)
        , health_attribute(health)
        , critRate_attribute(critRate) {}

    virtual ~Item() {}

    // Getter
    string getItemName() const { return itemName; }
	int getItemID() const { return itemID; }
    int getPrice() const { return price; }
    int getAttackPower() const { return attackPower_attribute; }
    int getHealth() const { return health_attribute; }
    int getCritRate() const { return critRate_attribute; }

    // Setter
    void setItemName(const string& name) { itemName = name; }
	void setItemID(int id) { itemID = id; }
    void setPrice(int p) { price = p; }
    void setAttackPower(int attackPower) { attackPower_attribute = attackPower; }
    void setHealth(int health) { health_attribute = health; }
    void setCritRate(int critRate) { critRate_attribute = critRate; }
};
