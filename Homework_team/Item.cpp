#include "Item.h"
#include <string>

using namespace std;

// 순서 : 이름, 아이템ID(0:무기, 1:방어구, 2:포션), 가격, 공격력, 체력, 크리티컬 확률

class DamageWeapon : public Item //아이템 상속 : 무기
{
public:
	DamageWeapon() : Item("DamageWeapon", 0, 150, 40, 0, 0) {};
};

class CritWeapon : public Item //아이템 상속 : 무기
{
public:
	CritWeapon() : Item("CritWeapon", 0, 140, 10, 0, 30) {};
};

class Amour : public Item //아이템 상속 : 방어구
{
public:
	Amour() : Item("Amour", 1, 110, 0, 150, 0) {};
};

class healthPotion : public Item //아이템 상속 : 체력포션
{
public:
	healthPotion() : Item("Health Potion", 2, 50, 0, 50, 0) {};
};

class powerPotion : public Item //아이템 상속 : 데미지 증가 포션
{
public:
	powerPotion() : Item("Power Potion", 2, 50, 10, 0, 0) {};
};

class CritPotion : public Item //아이템 상속 : 크리티컬 확률 증가 포션
{
public:
	CritPotion() : Item("Crit Potion", 2, 50, 0, 0, 10) {};
};