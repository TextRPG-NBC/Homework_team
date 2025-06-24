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
	{}

void Character::displayInfo() const {											//ĳ���� ����
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << gold << endl;
}

vector<Item> Character::invenrotoryInfo() // �κ��丮 ����  
{  
    vector<Item> totalitems;  

    if (weaponEquipment != nullptr)
    {  
        totalitems.push_back(*weaponEquipment);  
    }  

    if (armourEquipment != nullptr)
    {  
        totalitems.push_back(*armourEquipment);  
    }  

    for (const Item* item : inventory)
    {  
        totalitems.push_back(*item);
    }  

	for (const Item* item : potionBag)
	{
		totalitems.push_back(*item);
	}

    return totalitems;  
}




void Character::addExp(int amount)												//����ġ ȹ��
{
	exp += amount;
	cout << name << amount << " exp points up!" << endl;
	if (exp >= 100)
	{
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

void Character::addEquipment(Item* item, int ItemID) // 0: ����, 1: ��  
{  
    if (ItemID == 0) // ���� ����  
    {  
        if (weaponEquipment == nullptr)  
        {  
            weaponEquipment = item; // �� ���� ����  
            addStatus(item); // �� ���� �ɷ�ġ ����  
            cout << "you equip Weapon " << item->getItemName() << endl;  
        }  
        else  
        {  
            removeStatus(weaponEquipment); // ���� ���� �ɷ�ġ ����  
            inventory.push_back(weaponEquipment); // ���� ���⸦ �κ��丮�� �߰�  
            cout << "equipped " << weaponEquipment->getItemName() << " put in bag" << endl;  
            cout << "now you equip " << item->getItemName() << endl;  
            weaponEquipment = item; // �� ���� ����  
            addStatus(item); // �� ���� �ɷ�ġ ����  
        }  
    }  
    else if (ItemID == 1) // �� ����  
    {  
        if (armourEquipment == nullptr)
        {  
            armourEquipment = item; // �� �� ����  
            addStatus(item); // �� �� �ɷ�ġ ����  
            cout << "you equip Armour " << item->getItemName() << endl;  
        }  
        else  
        {  
            removeStatus(armourEquipment); // ���� �� �ɷ�ġ ����  
            inventory.push_back(armourEquipment); // ���� ���� �κ��丮�� �߰�  
            cout << "equipped " << armourEquipment->getItemName() << " put in bag" << endl;  
            cout << "now you equip " << item->getItemName() << endl;  
            armourEquipment = item; // �� �� ����  
            addStatus(item); // �� �� �ɷ�ġ ����  
        }  
    }  
    else  
    {  
        cout << "Invalid equipment type." << endl;  
    }  
}


void Character::deleteEquipment(Item* item, int ItemID)				//��� ����
{
	if (ItemID == 0) // ������ ���	
		{
		if (weaponEquipment == nullptr)	
		{
			cout << "No equipment this parts" << endl;
		}
		else if (weaponEquipment != nullptr)						 
		{
			weaponEquipment = nullptr;								//��� �ʱ�ȭ
		}
	}
	else if (ItemID == 1) // ���� ���	
	{
		if (armourEquipment == nullptr)							
		{
			cout << "No equipment this parts" << endl;
		}
		else if (armourEquipment != nullptr)						 //�� �ʱ�ȭ
		{
			armourEquipment = nullptr;
		}
	}
}

void Character::addStatus(Item* item)
{
	attackPower += item->getAttackPower();
	health += item->getHealth();
	criticalRate += item->getCritRate();
}

void Character::removeStatus(Item* item)
{
	attackPower -= item->getAttackPower();
	health -= item->getHealth();
	criticalRate -= item->getCritRate();
}

int Character::attack(Monster* target)
{

	return 0;
}


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
		inventory.push_back(item);
		
		if (item->getItemID() == 2) // �������� ������ ���
		{
			potionBag.push_back(item);
		}
		else if (item->getItemID() == 0 || item->getItemID() == 1) // �������� ���⳪ ���� ���
		{
			addEquipment(item, item->getItemID());
		}
		else
		{
			cout << "error" << endl;
		}
	}
}

void Character::sellItem(Item* item)							// ������ �Ǹ�
{
	gold += item->getPrice();									// ��� ȹ��

	if (item->getItemID() == 2)										//���� ����
	{        auto potionIt = std::find(potionBag.begin(), potionBag.end(), item);
        if (potionIt != potionBag.end())
		{
            potionBag.erase(potionIt);
        }
	}
	else if (item->getItemID() == 0 || item->getItemID() == 1)		 //��� ���� 
	{
		deleteEquipment(item, item->getItemID());				
	}
	else
	{
		NULL;
	}
}



void Character::addItem(Item* item)
{
	if (item->getItemID() == 2)
	{
		potionBag.push_back(item);
	}
	else if (item->getItemID() == 0 || item->getItemID() == 1) 
	{
		int itemIdCheck = item->getItemID();
		if (itemIdCheck){
			addEquipment(item, itemIdCheck);
			inventory.push_back(item); // �������� �κ��丮�� �߰�
		}
	}
	else
	{
		NULL;
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

		potionBag.erase(potionBag.begin() + selectItem);
		addStatus(item); // ������ �ɷ�ġ ����
		cout << "you used" << item->getItemName();
	}
}

void Character::addGold(int amount)
{
	gold += amount;
}