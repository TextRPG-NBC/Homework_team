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


void Character::displayInfo() const {											//Ä³ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << gold << endl << endl;
}

vector<Item*> Character::inventoryInfo() // ï¿½Îºï¿½ï¿½ä¸® ï¿½ï¿½ï¿½ï¿½  
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

void Character::addEquipment(Item* item, int ItemID) // 0: ï¿½ï¿½ï¿½ï¿½, 1: ï¿½ï¿½î±? 
{  
    if (ItemID == 0) // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½  
    {  
        if (weaponEquipment == nullptr)  
        {  
            weaponEquipment = item; // ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½  
            addStatus(item); // ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½É·ï¿½Ä¡ ï¿½ï¿½ï¿½ï¿½  
            cout << "you equip Weapon " << item->getItemName() << endl;  
        }  
        else  
        {  
			removeStatus(weaponEquipment); // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½É·ï¿½Ä¡ ï¿½ï¿½ï¿½ï¿½  
            inventory.push_back(weaponEquipment); // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½â¸¦ ï¿½Îºï¿½ï¿½ä¸®ï¿½ï¿½ ï¿½ß°ï¿½  
            cout << "equipped " << weaponEquipment->getItemName() << " put in bag" << endl;  
            cout << "now you equip " << item->getItemName() << endl;  
            weaponEquipment = item; // ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½  
            addStatus(item); // ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½É·ï¿½Ä¡ ï¿½ï¿½ï¿½ï¿½  
        }  
    }  
    else if (ItemID == 1) // ï¿½ï¿½î±?ï¿½ï¿½ï¿½ï¿½  
    {  
        if (armourEquipment == nullptr)
        {  
            armourEquipment = item; // ï¿½ï¿½ ï¿½ï¿½î±?ï¿½ï¿½ï¿½ï¿½  
            addStatus(item); // ï¿½ï¿½ ï¿½ï¿½î±?ï¿½É·ï¿½Ä¡ ï¿½ï¿½ï¿½ï¿½  
            cout << "equip : " << item->getItemName() << endl;  
        }  
        else  
        {  
            removeStatus(armourEquipment); // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½î±?ï¿½É·ï¿½Ä¡ ï¿½ï¿½ï¿½ï¿½  
            inventory.push_back(armourEquipment); // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½î±¸ï¿½ï¿?ï¿½Îºï¿½ï¿½ä¸®ï¿½ï¿½ ï¿½ß°ï¿½  
            cout << "equipped : " << armourEquipment->getItemName() << " put in bag" << endl;  
            cout << "now you equip " << item->getItemName() << endl;  
            armourEquipment = item; // ï¿½ï¿½ ï¿½ï¿½î±?ï¿½ï¿½ï¿½ï¿½  
            addStatus(item); // ï¿½ï¿½ ï¿½ï¿½î±?ï¿½É·ï¿½Ä¡ ï¿½ï¿½ï¿½ï¿½  
        }  
    }  
    else  
    {  
        cout << "Invalid equipment type." << endl;  
    }  
}


void Character::deleteEquipment(Item* item, int ItemID)		//ï¿½ï¿½ï¿?ï¿½ï¿½ï¿½ï¿½
{
	if (ItemID == 0)											// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿?
		{
		if (weaponEquipment == nullptr)	
		{
			cout << "No equipment this parts" << endl;
		}
		else if (weaponEquipment != nullptr)						 
		{
			removeStatus(item);										// ï¿½É·ï¿½Ä¡ ï¿½ï¿½ï¿½ï¿½
			weaponEquipment = nullptr;								//ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½

			for(int i = 0; i < inventory.size(); i++)
				{
				if (inventory[i]->getItemID() == 0)					// ï¿½Îºï¿½ï¿½ä¸®ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ È®ï¿½ï¿½
					{
					weaponEquipment = inventory[i];
					inventory.erase(inventory.begin()+i);					// ï¿½Îºï¿½ï¿½ä¸®ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
					addStatus(weaponEquipment);
					break;
					}
				}
		}
	}

	else if (ItemID == 1)										// ï¿½ï¿½î±¸ï¿½ï¿?ï¿½ï¿½ï¿?
	{
		if (armourEquipment == nullptr)							
		{
			cout << "No equipment this parts" << endl;
		}
		else if (armourEquipment != nullptr)						 //ï¿½ï¿½î±?ï¿½Ê±ï¿½È­
		{
			armourEquipment = nullptr;								// ï¿½ï¿½î±?ï¿½ï¿½ï¿½ï¿½
			removeStatus(item);										// ï¿½É·ï¿½Ä¡ ï¿½ï¿½ï¿½ï¿½
			
				for (int i = 0; i < inventory.size(); i++)
				{
					if (inventory[i]->getItemID() == 1)					// ï¿½Îºï¿½ï¿½ä¸®ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ È®ï¿½ï¿½
					{
						armourEquipment = inventory[i];
						inventory.erase(inventory.begin()+i);					// ï¿½Îºï¿½ï¿½ä¸®ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
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
		damage *= 2;			// Å©ï¿½ï¿½Æ¼ï¿½Ã½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ ï¿½ï¿½
	}
	
	return damage;
}


void Character::buyItem(Item* item)											//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
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
		
		if (item->getItemID() == 2) // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿?
		{
			potionBag.push_back(item);
		}
		else if (item->getItemID() == 0 || item->getItemID() == 1) // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½â³ª ï¿½ï¿½î±¸ï¿½ï¿?ï¿½ï¿½ï¿?
		{
			addEquipment(item, item->getItemID());
		}
		else
		{
			cout << "error" << endl;
		}
	}
}

void Character::sellItem(Item* item)							// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ç¸ï¿½
{
	gold += item->getPrice();									// ï¿½ï¿½ï¿?È¹ï¿½ï¿½

	if (item->getItemID() == 2)										//ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
	{        
		auto potionIt = std::find(potionBag.begin(), potionBag.end(), item);
        if (potionIt != potionBag.end())
		{
            potionBag.erase(potionIt);
        }
	}
	else if (item->getItemID() == 0 || item->getItemID() == 1)		 //ï¿½ï¿½ï¿?ï¿½ï¿½ï¿½ï¿½ 
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
			inventory.push_back(item); // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Îºï¿½ï¿½ä¸®ï¿½ï¿½ ï¿½ß°ï¿½
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
	if (potionBag.empty())
	{
		cout << "potion is empty!" << endl;
	}
	else
	{
		for (int i = 0; i < potionBag.size(); i++)
		{
			cout << i << ". " << potionBag[i]->getItemName() << endl;
		}
		int selectItem;
		cout << "Select item to use: ";
		cin >> selectItem;

		addStatus(potionBag[selectItem]); // ¾ÆÀÌÅÛ ´É·ÂÄ¡ Àû¿ë
		cout << "you used" << potionBag[selectItem]->getItemName();
		potionBag.erase(potionBag.begin() + selectItem);
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
