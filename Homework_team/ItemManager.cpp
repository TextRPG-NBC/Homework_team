#include "ItemManager.h"
#include "Item.h"


ItemManager::ItemManager()
{
    if (!itemVector.empty()) {
        return;
    }

    itemVector.resize(6);

    itemVector[0] = new Item("DamageWeapon", 0, 150, 40, 0, 0);
    itemVector[1] = new Item("CritWeapon", 0, 140, 10, 0, 30);
    itemVector[2] = new Item("Amour", 1, 110, 0, 150, 0);
    itemVector[3] = new Item("Health Potion", 2, 50, 0, 50, 0);
    itemVector[4] = new Item("Power Potion", 2, 50, 10, 0, 0);
    itemVector[5] = new Item("Crit Potion", 2, 50, 0, 0, 10);
}

ItemManager::~ItemManager()
{
    for (Item* item : itemVector) {
        delete item;
    }
}

vector<Item*> ItemManager::getItemListVector()
{
    return itemVector;
}

Item* ItemManager::getRandomItem()
{
    int randomIndex = RandomUtil::getInt(0, itemVector.size());
    return itemVector[randomIndex];
}
