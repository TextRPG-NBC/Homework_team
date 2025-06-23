#include "ItemManager.h"
#include "Item.h"

// ���� : �̸�, ������ID(0:����, 1:��, 2:����), ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
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

Item* ItemManager::randomItem() // ��ȯ ������ Item*�� ����
{
    if (itemVector.empty()) {
        getItemListVector();
    }
    int randomIndex = rand() % itemVector.size();
    return itemVector[randomIndex];
}
