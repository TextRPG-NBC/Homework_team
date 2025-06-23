#include "Item.h"
#include <string>

using namespace std;

// ���� : �̸�, ������ID(0:����, 1:��, 2:����), ����, ���ݷ�, ü��, ũ��Ƽ�� Ȯ��

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

class Amour : public Item //������ ��� : ��
{
public:
	Amour() : Item("Amour", 1, 110, 0, 150, 0) {};
};

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