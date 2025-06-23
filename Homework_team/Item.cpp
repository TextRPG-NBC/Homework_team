
#pragma once

#include "Item.h"
#include <string>

using namespace std;

Item::Item(string name, int price, int attackPower, int health, int critRate)
	: itemName(name), price(price), attackPower_attribute(attackPower), health_attribute(health), critRate_attribute(critRate) {
};

class healthPotion : public Item //아이템 상속 : 체력포션
{
public:
	healthPotion() : Item("Health Potion", 50, 0, 50, 0) {}; // 순서 : 이름, 가격, 공격력, 체력, 크리티컬 확률
};

class powerPotion : public Item //아이템 상속 : 데미지 증가 포션
{
public:
	powerPotion() : Item("Power Potion", 50, 10, 0, 0) {}; // 순서 : 이름, 가격, 공격력, 체력, 크리티컬 확률
};

class CritPotion : public Item //아이템 상속 : 크리티컬 확률 증가 포션
{
public:
	CritPotion() : Item("Crit Potion", 50, 0, 0, 10) {}; // 아이템 이름, 가격, 공격력, 체력, 크리티컬 확률
		
};

//	case Item::healthPotion: // 아이템 종류에 따라 객체 생성??
//	return new healthPotion();