
#pragma once

#include "Item.h"
#include <string>

using namespace std;

Item::Item(string name, int itemID, int price, int attackPower, int health, int critRate)
	: itemName("name")
	, itemID(0)
	, price(0)
	, attackPower_attribute(0)
	, health_attribute(0)
	, critRate_attribute(0) {};


class DamageWeapon : public Item //아이템 상속 : 무기
{
public:
	DamageWeapon() : Item("DamageWeapon", 1, 150, 40, 0, 0) {}; // 순서 : 이름, 아이템ID(0:무기, 1:방어구, 2:포션), 가격, 공격력, 체력, 크리티컬 확률
};

class CritWeapon : public Item //아이템 상속 : 무기
{
public:
	CritWeapon() : Item("DamageWeapon", 1, 140, 10, 0, 30) {}; // 순서 : 이름, 아이템ID(0:무기, 1:방어구, 2:포션), 가격, 공격력, 체력, 크리티컬 확률
};

class Amour : public Item //아이템 상속 : 방어구
{
public:
	Amour() : Item("Amour", 1, 110, 0, 150, 0) {}; // 순서 : 이름, 아이템ID(0:무기, 1:방어구, 2:포션), 가격, 공격력, 체력, 크리티컬 확률
};

class healthPotion : public Item //아이템 상속 : 체력포션
{
public:
	healthPotion() : Item("Health Potion", 3, 50, 0, 50, 0) {}; // 순서 : 이름, 아이템ID(0:무기, 1:방어구, 2:포션), 가격, 공격력, 체력, 크리티컬 확률
};

class powerPotion : public Item //아이템 상속 : 데미지 증가 포션
{
public:
	powerPotion() : Item("Power Potion", 3, 50, 10, 0, 0) {}; // 순서 : 이름, 아이템ID(0:무기, 1:방어구, 2:포션), 가격, 공격력, 체력, 크리티컬 확률
};

class CritPotion : public Item //아이템 상속 : 크리티컬 확률 증가 포션
{
public:
	CritPotion() : Item("Crit Potion", 3, 50, 0, 0, 10) {}; // 순서 : 이름, 아이템ID(0:무기, 1:방어구, 2:포션), 가격, 공격력, 체력, 크리티컬 확률
		
};



//	case Item::healthPotion: // 아이템 종류에 따라 객체 생성??
//	return new healthPotion();