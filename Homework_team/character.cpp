#include "character.h"
#include "Item.h"
#include "Monster.h"

using namespace std;

Character::Character(const string& name)
	: name(name)
	, level(1)
	, additionalHealth(0)
	, exp(0)
	, health(200)
	, attackPower(30)
	, criticalRate(0)
	, gold(0)
	, playerState(State::ALIVE)
	, weaponEquipment(nullptr)
	, armourEquipment(nullptr)
	{}


void Character::displayInfo() const {											//ĳ���� ����
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << gold << endl << endl;
}

vector<Item*> Character::inventoryInfo() // �κ��丮 ����  
{  
    vector<Item*> totalitems;  

    if (weaponEquipment != nullptr)
    {  
        totalitems.push_back(weaponEquipment);  
    }  

    if (armourEquipment != nullptr)
    {  
        totalitems.push_back(armourEquipment);  
    }  

    for (Item* item : inventory)
    {  
        totalitems.push_back(item);
    }  

	for (Item* item : potionBag)
	{
		totalitems.push_back(item);
	}

    return totalitems;  
}

void Character::addExp(int amount)	
{
	exp += amount;
	cout << name << amount << " exp points up!" << endl;
	if (exp >= 100)												//level up
	{
		exp = 0;
		level++;
		health = 180 + (level * 20) + additionalHealth;
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
            cout << "equip : " << item->getItemName() << endl;  
        }  
        else  
        {  
            removeStatus(armourEquipment); // ���� �� �ɷ�ġ ����  
            inventory.push_back(armourEquipment); // ���� ���� �κ��丮�� �߰�  
            cout << "equipped : " << armourEquipment->getItemName() << " put in bag" << endl;  
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


void Character::deleteEquipment(Item* item, int ItemID)		//��� ����
{
	if (ItemID == 0)											// ������ ���	
		{
		if (weaponEquipment == nullptr)	
		{
			cout << "No equipment this parts" << endl;
		}
		else if (weaponEquipment != nullptr)						 
		{
			removeStatus(item);										// �ɷ�ġ ����
			weaponEquipment = nullptr;								//���� ����

			for(int i = 0; i < inventory.size(); i++)
				{
				if (inventory[i]->getItemID() == 0)					// �κ��丮���� ���� ������ Ȯ��
					{
					weaponEquipment = inventory[i];
					inventory.erase(inventory.begin()+i);					// �κ��丮���� ����
					addStatus(weaponEquipment);
					break;
					}
				}
		}
	}

	else if (ItemID == 1)										// ���� ���	
	{
		if (armourEquipment == nullptr)							
		{
			cout << "No equipment this parts" << endl;
		}
		else if (armourEquipment != nullptr)						 //�� �ʱ�ȭ
		{
			armourEquipment = nullptr;								// �� ����
			removeStatus(item);										// �ɷ�ġ ����
			
				for (int i = 0; i < inventory.size(); i++)
				{
					if (inventory[i]->getItemID() == 1)					// �κ��丮���� ���� ������ Ȯ��
					{
						armourEquipment = inventory[i];
						inventory.erase(inventory.begin()+i);					// �κ��丮���� ����
						addStatus(armourEquipment);
						break;
					}
				}
			}
	}
}

void Character::addStatus(Item* item)
{
	attackPower += item->getAttackPower();
	additionalHealth += item->getHealth();
	health += item->getHealth();
	criticalRate += item->getCritRate();
}

void Character::removeStatus(Item* item)
{
	attackPower -= item->getAttackPower();
	health -= item->getHealth();
	criticalRate -= item->getCritRate();
}

int Character::attack(Character* player)
{	
	int damage = attackPower;
	int critCheck = rand() % 100;
	
	if (critCheck < player->criticalRate )
	{
		damage *= 2;			// ũ��Ƽ�ý� ������ �� ��
	}
	
	return damage;
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
	{        
		auto potionIt = std::find(potionBag.begin(), potionBag.end(), item);
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

void Character::useItem() 
{
	if(!potionBag.empty())
	{
		int potionNum = rand() % potionBag.size();
		addStatus(potionBag[potionNum]); // ������ �ɷ�ġ ����
		cout << "you used" << potionBag[potionNum]->getItemName();
		potionBag.erase(potionBag.begin() + potionNum);
	}
}

void Character::addGold(int amount)
{
	gold += amount;
}

void Character::setPlayerState(State state)
{
	playerState = state;
}
