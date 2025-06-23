#include "character.h"
#include "item.h"
#include "Monster.h"

using namespace std;

Character::Character(const string& name)
	: name(name)
	, level(0)
	, exp(0)
	, health(0)
	, attackPower(0)
	, criticalRate(0)
	, gold(0)
	, playerState(State::ALIVE)
{
	weaponEquipment.resize(2, nullptr);
	armourEquipment.resize(2, nullptr);
}

void Character::displayInfo() const {											//ĳ���� ����
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << gold << endl;

	if (armourEquipment.empty()) {
		cout << "Armour is empty!" << endl;									//��� ���� ���
	}
	else {
		for (Item* item : armourEquipment) {
			cout << "equipment Item: " << item->getItemName() << endl;				 //������ ��� ���
		}

	if (weaponEquipment.empty()) {
		cout << "Weapon is empty!" << endl;									//��� ���� ���
	}

	else 
		{
		for (Item* item : weaponEquipment)
			cout << "equipment Item: " << item->getItemName() << endl;				 //������ ��� ���
		}
	
	if (inventory.empty()) {
		cout << "Inventory is empty!" << endl;									//��� ���� ���
	}

	else {
		for (Item* item : inventory) {
			cout << "Inventory Item: " << item->getItemName() << endl;				 //������ ��� ���
		}
	}

	if (potionBag.empty()) {													//�Ҹ�ǰ�� ���� ���
		cout << "potion is empty!" << endl;
	}

	else {
		for (Item* item : potionBag) {
			cout << "Potion Item: " << item->getItemName() << endl;				 //������ �Ҹ�ǰ ���
		}
	}


void Character::gainExp(int amount)												//����ġ ȹ��
{
	exp += amount;
	cout << name << amount << " exp points up!" << endl;
	if (exp >= 100) {
		exp = 0;
		level++;
		health = 180 + (level * 20);
		attackPower = 25 + (level * 5);

		cout << name << " is level up! : " << level << endl;
	}
}


void Character::takeDamage(int damage)
{
	if (health - damage < 0)
	{
		health = 0;
		playerState = State::DEAD;
	}
	else
	{
		health -= damage;
	}
}

void Character::addEquipment(Item* item, int ItemID)							 // 0: ����, 1: ��
{
	if (equipment[ItemID] == NULL)
	{
		equipment.at(ItemID) = item;										//�� ��� ����
		addStatus(item);													//�� ��� �ɷ�ġ ����
		cout << "you equip Weapon" << item->getItemName() << endl;
	}
	else
	{
		deleteEquipment(equipment[ItemID], ItemID);							//�� ��� ����	
		removeStatus(equipment[ItemID]);									//�� ��� �ɷ�ġ ����
		cout << "equiped " << equipment[ItemID]->getItemName() << "put in bag" << endl;
		cout << "now you equip " << item->getItemName() << endl;
		equipment.at(ItemID) = item;										//�� ��� ����
		addStatus(item);													//�� ��� �ɷ�ġ ���� ����									
	}
}


void Character::deleteEquipment(Item* item, int position)					//��� ����
{
	if (equipment[position] == NULL)										 //��� ��������� �ƹ��͵� ���� ����
	{
		cout << "No equipment this parts" << endl;
	}
	else if (equipment[position] == item)									 //��� �����ϸ� �κ��丮�� �߰�
	{
		inventory.push_back(equipment[position]);							//�κ��丮�� â���ߴ� ��� �߰�		
		equipment.erase(equipment.begin() + position);
		cout << item->getItemName() << " removed from equipment." << endl;
		cout << "equiped " << equipment[position]->getItemName() << "put in bag" << endl;
		return;
	}
}

void Character::addStatus(Item* item)
{
	attackPower += item->getAttackPower();
	health += item->getHealth();
	criticalRate += item->getCritRate();
	cout << item->getItemName() << " added to equipment." << endl;
}

void Character::removeStatus(Item* item)
{
	attackPower += item->getAttackPower();
	health += item->getHealth();
	criticalRate += item->getCritRate();
	cout << item->getItemName() << " removed from equipment." << endl;
}

int Character::attack(Monster* target)
{

	return 0;
}

/*
void Character::buyItem(Item* item)											//������ ����
{
	if (gold < item->getPrice())
	{
		cout << "Not enough gold to buy " << item->getItemName() << "." << endl;
	}
	else
	{
		gold -= item->getPrice();
		cout << item->getItemName() << " bought for " << item->getPrice() << " gold." << endl;
		inventory.push_back(item);											 //������ �������� �κ��丮�� �߰�
	}
}

void Character::sellItem(Item* item)										 // ������ �Ǹ�
{
	gold += item->getPrice();
	if (item->getItemID() == 2) // �������� nullptr�� ��� ó��
	{
		PotionBag.erase(
			remove_if(PotionBag.begin(), PotionBag.end(), [](const Item& item) {}));
	}
	else if (item->getItemID() == 0 || 1) // �������� nullptr�� ��� ó��
	{
		inventory.erase(
			remove_if(inventory.begin(), inventory.end(),
				[item](Item* i) { return i == item; }),
			inventory.end()
		);
	}
	else
	{
		NULL; // �������� nullptr�� ��� ó��
	}
}
*/


void Character::addItem(Item* item)
{
	if (item->getItemID() == 2) // �������� nullptr�� ��� ó��
	{
		potionBag.push_back(item);
	}
	else if (item->getItemID() == 0 || 1) // �������� nullptr�� ��� ó��
	{
		int itemIdCheck = item->getItemID();
		if (itemIdCheck){
			addEquipment(item, itemIdCheck);
		inventory.push_back(item); // �������� �κ��丮�� �߰�
		}
	}
	else
	{
		NULL; // �������� nullptr�� ��� ó��
	}

	cout << item->getItemName() << " added to bag" << endl;
}

void Character::useItem(Item* item) //������ ���
{
	if (inventory.empty())
	{
		cout << "potion is empty!" << endl;
	}
	else
	{
		for (int i = 0; i <= inventory.size(); i++)
		{
			cout << i << ". " << inventory[i]->getItemName() << endl;
		}
		int selectItem;
		cout << "Select item to use: ";
		cin >> selectItem;

		equipment.erase(equipment.begin() + selectItem);
		addStatus(item); // ������ �ɷ�ġ ����
		cout << "you used" << item->getItemName();
	}
}

void Character::addGold(int amount)
{
	gold += amount;
}
