#include "character.h"
#include "item.h"

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
} 

void Character::displayInfo() const {											//ĳ���� ����
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << exp << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
    cout << "Critical Rate: " << criticalRate << "%" << endl;
    cout << "Have money : " << gold << endl;

	if (equipment.empty()) {
		cout << "equipment is empty!" << endl;									//��� ���� ���
	}
	else {
		for (Item* item : inventory) {
			cout << "equipment Item: " << item->itemName << endl;				 //������ ��� ���
		}
	}

	if (inventory.empty()) {
		cout << "Inventory is empty!" << endl;									//��� ���� ���
	} else {
		for (Item* item : inventory) {
			cout << "Inventory Item: " << item->itemName << endl;				 //������ ��� ���
		}
	}
	
	if (PotionBag.empty()) {													//�Ҹ�ǰ�� ���� ���
		cout << "potion is empty!" << endl;
	}
	else {
		for (Item* item : PotionBag) {
			cout << "Potion Item: " << item->itemName << endl;				 //������ �Ҹ�ǰ ���
		}
	}
}


void Character::gainExp(int amount)												//����ġ ȹ��
{
	exp += amount;
	cout << name << amount << " exp points up!" << endl;
	levelUp();
}

void Character::levelUp()														//������
{
	if (exp >= 100) {
		exp = 0;
		level++;
		health = 180 + (level * 20);
		attackPower = 25 + (level * 5);

		cout << name << " is level up! current level : " << level << endl;
	}
}


void Character::attack(Character* target)
{
	int damage = attackPower;													//���ݷ� ���
	if (rand() % 100 < criticalRate) {											//ũ��Ƽ�� Ȯ�� ����
		damage *= 2;															//ũ��Ƽ�� ��Ʈ �� ������ 2��
		cout << name << " landed a critical hit!" << endl;
	}
	////////////////////
	target->takeDamage(damage);												//��󿡰� ������ ����
	cout << name << " attacks " << target->name << " for " << damage << " damage." << endl;
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
		cout << "you equip Weapon" << item->itemName << endl;
	}
	else
	{
		deleteEquipment(equipment[ItemID], ItemID);							//�� ��� ����	
		removeStatus(equipment[ItemID]);									//�� ��� �ɷ�ġ ����
		cout << "equiped " << equipment[ItemID]->itemName<< "put in bag" << endl;
		cout << "now you equip " << item->itemName << endl;
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
		cout << item->itemName << " removed from equipment." << endl;
		cout << "equiped " << equipment[0]->itemName << "put in bag" << endl;
		return;
	}
		
}

void Character::addStatus(Item* item)
{
	attackPower += item->attackPower_attribute;
	health += item->health_attribute;
	criticalRate += item->critRate_attribute;
	cout << item->itemName << " added to equipment." << endl;
}

void Character::removeStatus(Item* item)
{
	attackPower -= item->attackPower_attribute;
	health -= item->health_attribute;
	criticalRate -= item->critRate_attribute;
	cout << item->itemName << " removed from equipment." << endl;
}


void Character::buyItem(Item* item)											//������ ����
{
	if (gold < item->price)
	{
		cout << "Not enough gold to buy " << item->itemName << "." << endl;
		return;
	}
	else
	{
		gold -= item->price;
		cout << item->itemName << " bought for " << item->price << " gold." << endl;
		inventory.push_back(item);											 //������ �������� �κ��丮�� �߰�
	}
}

void Character::sellItem(Item* item)										 // ������ �Ǹ�
{
    gold += item->price;
	if (item->itemID == 3) // �������� nullptr�� ��� ó��
	{
		PotionBag.erase(
			remove_if(PotionBag.begin(), PotionBag.end(), [](const Item& item) {}));
	}
	else if (item->itemID == 0 || 1) // �������� nullptr�� ��� ó��
	{
		inventory.push_back(item); // �������� �κ��丮�� �߰�
		inventory.erase(
			remove_if(inventory.begin(), inventory.end(), [](const Item& item) {}));
	}
	else
	{
		NULL; // �������� nullptr�� ��� ó��
	}
}

void Character::getItem(Item* item)
{
	if (item->itemID == 3) // �������� nullptr�� ��� ó��
	{
		PotionBag.push_back(item);
	}
	else if (item->itemID == 0 || 1) // �������� nullptr�� ��� ó��
	{	
		inventory.push_back(item); // �������� �κ��丮�� �߰�
	}
	else
	{
		NULL; // �������� nullptr�� ��� ó��
	}
	
	cout << item->itemName << " added to bag" << endl;
}

void Character::useItem(Item* item) //������ ���
{
	if (inventory.empty())
	{
		cout << "potion is empty!" << endl;
		return;
	}
	else
	{
		for (int i = 0; i <= inventory.size(); i++)
		{
			cout << i << ". " << inventory[i] << endl;
		}
		int selectItem;
		cout << "Select item to use: ";
		cin >> selectItem;

		equipment.erase(equipment.begin() + selectItem);
		addStatus(item); // ������ �ɷ�ġ ����
		cout << "you used" << item->itemName;
	}
}

void Character::addGold(int amount)
{
	gold += amount;
}


