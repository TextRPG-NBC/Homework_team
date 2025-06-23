
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


class DamageWeapon : public Item //������ ��� : ����
{
public:
	DamageWeapon() : Item("DamageWeapon", 1, 150, 40, 0, 0) {}; // ���� : �̸�, ������ID(0:����, 1:��, 2:����), ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
};

class CritWeapon : public Item //������ ��� : ����
{
public:
	CritWeapon() : Item("DamageWeapon", 1, 140, 10, 0, 30) {}; // ���� : �̸�, ������ID(0:����, 1:��, 2:����), ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
};

class Amour : public Item //������ ��� : ��
{
public:
	Amour() : Item("Amour", 1, 110, 0, 150, 0) {}; // ���� : �̸�, ������ID(0:����, 1:��, 2:����), ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
};

class healthPotion : public Item //������ ��� : ü������
{
public:
	healthPotion() : Item("Health Potion", 3, 50, 0, 50, 0) {}; // ���� : �̸�, ������ID(0:����, 1:��, 2:����), ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
};

class powerPotion : public Item //������ ��� : ������ ���� ����
{
public:
	powerPotion() : Item("Power Potion", 3, 50, 10, 0, 0) {}; // ���� : �̸�, ������ID(0:����, 1:��, 2:����), ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
};

class CritPotion : public Item //������ ��� : ũ��Ƽ�� Ȯ�� ���� ����
{
public:
	CritPotion() : Item("Crit Potion", 3, 50, 0, 0, 10) {}; // ���� : �̸�, ������ID(0:����, 1:��, 2:����), ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
		
};



//	case Item::healthPotion: // ������ ������ ���� ��ü ����??
//	return new healthPotion();