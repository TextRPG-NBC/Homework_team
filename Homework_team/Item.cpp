
#pragma once

#include "Item.h"
#include <string>

using namespace std;

Item::Item(string name, int price, int attackPower, int health, int critRate)
	: itemName(name), price(price), attackPower_attribute(attackPower), health_attribute(health), critRate_attribute(critRate) {
};

class healthPotion : public Item //������ ��� : ü������
{
public:
	healthPotion() : Item("Health Potion", 50, 0, 50, 0) {}; // ���� : �̸�, ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
};

class powerPotion : public Item //������ ��� : ������ ���� ����
{
public:
	powerPotion() : Item("Power Potion", 50, 10, 0, 0) {}; // ���� : �̸�, ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
};

class CritPotion : public Item //������ ��� : ũ��Ƽ�� Ȯ�� ���� ����
{
public:
	CritPotion() : Item("Crit Potion", 50, 0, 0, 10) {}; // ������ �̸�, ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��
		
};

//	case Item::healthPotion: // ������ ������ ���� ��ü ����??
//	return new healthPotion();