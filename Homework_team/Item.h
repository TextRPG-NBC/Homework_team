#pragma once
#include "CommonInclude.h"

using namespace std;

class Item {
private:
    string itemName;
    int itemID; // 0:����, 1 : ��, 2 : ����
    int attackPower_attribute;
    int health_attribute; 
    int critRate_attribute;
    int price;

public:
    Item()
        : itemName("None")
        , itemID(-1)
        , price(0)
        , attackPower_attribute(0)
        , health_attribute(0) 
        , critRate_attribute(0)
    {}

    Item(string name, int itemID, int price, int attackPower, int health, int critRate)
        : itemName(name)
        , itemID(itemID)
        , price(price)
        , attackPower_attribute(attackPower)
        , health_attribute(health) 
        , critRate_attribute(critRate) {}
    Item(const Item& item)
        : itemName(item.itemName)
        , itemID(item.itemID)
        , price(item.price)
        , attackPower_attribute(item.attackPower_attribute)
        , health_attribute(item.health_attribute)
        , critRate_attribute(item.critRate_attribute) {}
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

// ���� : �̸�, ������ID(0:����, 1:��, 2:����), ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��


//����
class DamageWeapon : public Item //������ ��� : ����
{
public:
    DamageWeapon() : Item("DamageWeapon", 0, 150, 40, 0, 0) {};
};

class CritWeapon : public Item //������ ��� : ����
{
public:
    CritWeapon() : Item("CritWeapon", 0, 140, 10, 0, 30) {};
};


//��
class Armour : public Item //������ ��� : ��
{
public:
    Armour() : Item("Amour", 1, 110, 0, 150, 0) {};
};


//����
class healthPotion : public Item //������ ��� : ü������
{
public:
    healthPotion() : Item("Health Potion", 2, 50, 0, 50, 0) {};
};

class powerPotion : public Item //������ ��� : ������ ���� ����
{
public:
    powerPotion() : Item("Power Potion", 2, 50, 10, 0, 0) {};
};

class CritPotion : public Item //������ ��� : ũ��Ƽ�� Ȯ�� ���� ����
{
public:
    CritPotion() : Item("Crit Potion", 2, 50, 0, 0, 10) {};
};