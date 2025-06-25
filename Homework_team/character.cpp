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


void Character::displayInfo() const {											      
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Exp: " << exp << endl;
	cout << "Hp: " << health << endl;
	cout << "Attack: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Deposit: " << gold << endl << endl;
}

vector<Item*> Character::inventoryInfo() 
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
	if (exp >= 100)												//level up
	{
		exp = 0;
		level++;
		health = 180 + (level * 20) + additionalHealth;
		attackPower = 25 + (level * 5);

		cout << "Level Up!(" << level - 1 << " -> " << level << ")" << endl;
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

void Character::addEquipment(Item* item, int ItemID)
{  
    if (ItemID == 0)            
    {  
        if (weaponEquipment == nullptr)  
        {  
            weaponEquipment = item;    
            addStatus(item); 
            cout << name << " equipped " << item->getItemName() << endl;
        }  
        else  
        {  
			removeStatus(weaponEquipment); 
            inventory.push_back(weaponEquipment);
            cout << weaponEquipment->getItemName() << " is unequipped" << endl;  
			cout << name << " equipped " << item->getItemName() << endl;
            weaponEquipment = item;             
            addStatus(item);            
        }  
    }  
    else if (ItemID == 1)       
    {  
        if (armourEquipment == nullptr)
        {  
            armourEquipment = item;     
            addStatus(item);  
			cout << name << " equipped " << item->getItemName() << endl;
        }  
        else  
        {  
            removeStatus(armourEquipment);    
            inventory.push_back(armourEquipment); 
			cout << weaponEquipment->getItemName() << " is unequipped" << endl;
			cout << name << " equipped " << item->getItemName() << endl;
            armourEquipment = item; 
            addStatus(item); 
        }  
    }  
    else  
    {  
        cout << "Invalid equipment type." << endl;  
    }  
}


void Character::deleteEquipment(Item* item, int ItemID)		      
{
	if (ItemID == 0)											           	
		{
		if (weaponEquipment == nullptr)	
		{
			cout << "No equipment this parts" << endl;
		}
		else if (weaponEquipment != nullptr)						 
		{
			removeStatus(item);										     
			weaponEquipment = nullptr;								         

			for(int i = 0; i < inventory.size(); i++)
				{
				if (inventory[i]->getItemID() == 0)					  
					{
					weaponEquipment = inventory[i];
					inventory.erase(inventory.begin()+i);					    
					addStatus(weaponEquipment);
					break;
					}
				}
		}
	}

	else if (ItemID == 1)									  	
	{
		if (armourEquipment == nullptr)							
		{
			cout << "No equipment this parts" << endl;
		}
		else if (armourEquipment != nullptr)						
		{
			armourEquipment = nullptr;							 
			removeStatus(item);									  
			
				for (int i = 0; i < inventory.size(); i++)
				{
					if (inventory[i]->getItemID() == 1)					
					{
						armourEquipment = inventory[i];
						inventory.erase(inventory.begin()+i);			        
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
		damage *= 2;			        
	}
	
	return damage;
}


void Character::buyItem(Item* item)											      
{
	if (gold < item->getPrice())
	{
		cout << "NOT ENOUGH MONEY!!\n";
	}
	else
	{
		gold -= item->getPrice();
		cout << "BUY " << item->getItemName() << "\n";
		inventory.push_back(item);
		
		if (item->getItemID() == 2)                  
		{
			potionBag.push_back(item);
		}
		else if (item->getItemID() == 0 || item->getItemID() == 1)  
		{
			addEquipment(item, item->getItemID());
		}
		else
		{
			cout << "!!!Error!!!\n";
		}
	}
}

void Character::sellItem(Item* item)							
{
	gold += item->getPrice();									

	if (item->getItemID() == 2)										 
	{        
		auto potionIt = std::find(potionBag.begin(), potionBag.end(), item);
        if (potionIt != potionBag.end())
		{
            potionBag.erase(potionIt);
        }
	}
	else if (item->getItemID() == 0 || item->getItemID() == 1)		  
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
			inventory.push_back(item); 
		}
	}
	else
	{
		NULL;
	}
}

void Character::useItem() 
{
	if(!potionBag.empty())
	{
		int potionNum = rand() % potionBag.size();
		addStatus(potionBag[potionNum]);   
		//std::cout << name << "이(가) " << potionBag[potionNum]->getItemName() << "를 사용했습니다." << endl;
		std::cout << name << " use " << potionBag[potionNum]->getItemName() << endl;
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