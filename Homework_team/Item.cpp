// PotionItems.h
#pragma once
#include "Item.h"

class healthPotion : public Item {
public:
    healthPotion() : Item("Health Potion", 50, 0, 50, 0) {}
};

class powerPotion : public Item {
public:
    powerPotion() : Item("Power Potion", 50, 10, 0, 0) {}
};

class critPotion : public Item {
public:
    critPotion() : Item("Crit Potion", 50, 0, 0, 10) {}
};

