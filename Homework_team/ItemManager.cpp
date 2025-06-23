#include "ItemManager.h"
#include "Item.h"

// 순서 : 이름, 아이템ID(0:무기, 1:방어구, 2:포션), 가격, 공격력, 체력, 크리티컬 확률
void ItemManager::getItemListVector()  
{  
    itemVector.clear();  
    itemVector.push_back(new Item("DamageWeapon", 0, 150, 40, 0, 0));
    itemVector.push_back(new Item("CritWeapon", 0, 140, 10, 0, 30));
    itemVector.push_back(new Item("Amour", 1, 110, 0, 150, 0));
    itemVector.push_back(new Item("Health Potion", 2, 50, 0, 50, 0));
    itemVector.push_back(new Item("Power Potion", 2, 50, 10, 0, 0));
    itemVector.push_back(new Item("Crit Potion", 2, 50, 0, 0, 10));
}

Item* ItemManager::randomItem() // 반환 형식을 Item*로 수정
{
    if (itemVector.empty()) {
        getItemListVector();
    }
    int randomIndex = rand() % itemVector.size();
    return itemVector[randomIndex];
}
