#include "character.h"
#include "Item.h"
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

void Character::displayInfo() const {											//캐릭터 정보
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << gold << endl << endl;
}

vector<Item*> Character::inventoryInfo() // 인벤토리 리턴  
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

void Character::addEquipment(Item* item, int ItemID) // 0: 무기, 1: 방어구  
{  
    if (ItemID == 0) // 무기 장착  
    {  
        if (weaponEquipment == nullptr)  
        {  
            weaponEquipment = item; // 새 무기 장착  
            addStatus(item); // 새 무기 능력치 적용  
            cout << "you equip Weapon " << item->getItemName() << endl;  
        }  
        else  
        {  
			removeStatus(weaponEquipment); // 기존 무기 능력치 제거  
            inventory.push_back(weaponEquipment); // 기존 무기를 인벤토리에 추가  
            cout << "equipped " << weaponEquipment->getItemName() << " put in bag" << endl;  
            cout << "now you equip " << item->getItemName() << endl;  
            weaponEquipment = item; // 새 무기 장착  
            addStatus(item); // 새 무기 능력치 적용  
        }  
    }  
    else if (ItemID == 1) // 방어구 장착  
    {  
        if (armourEquipment == nullptr)
        {  
            armourEquipment = item; // 새 방어구 장착  
            addStatus(item); // 새 방어구 능력치 적용  
            cout << "you equip Armour " << item->getItemName() << endl;  
        }  
        else  
        {  
            removeStatus(armourEquipment); // 기존 방어구 능력치 제거  
            inventory.push_back(armourEquipment); // 기존 방어구를 인벤토리에 추가  
            cout << "equipped " << armourEquipment->getItemName() << " put in bag" << endl;  
            cout << "now you equip " << item->getItemName() << endl;  
            armourEquipment = item; // 새 방어구 장착  
            addStatus(item); // 새 방어구 능력치 적용  
        }  
    }  
    else  
    {  
        cout << "Invalid equipment type." << endl;  
    }  
}


void Character::deleteEquipment(Item* item, int ItemID)		//장비 제거
{
	if (ItemID == 0)											// 무기의 경우	
		{
		if (weaponEquipment == nullptr)	
		{
			cout << "No equipment this parts" << endl;
		}
		else if (weaponEquipment != nullptr)						 
		{
			removeStatus(item);										// 능력치 제거
			weaponEquipment = nullptr;								//무기 제거

			for(int i = 0; i < inventory.size(); i++)
				{
				if (inventory[i]->getItemID() == 0)					// 인벤토리에서 무기 아이템 확인
					{
					weaponEquipment = inventory[i];
					inventory.erase(inventory.begin()+i);					// 인벤토리에서 제거
					addStatus(weaponEquipment);
					break;
					}
				}
		}
	}
	else if (ItemID == 1)										// 방어구의 경우	
	{
		if (armourEquipment == nullptr)							
		{
			cout << "No equipment this parts" << endl;
		}
		else if (armourEquipment != nullptr)						 //방어구 초기화
		{
			armourEquipment = nullptr;								// 방어구 제거
			removeStatus(item);										// 능력치 제거
			
				for (int i = 0; i < inventory.size(); i++)
				{
					if (inventory[i]->getItemID() == 1)					// 인벤토리에서 무기 아이템 확인
					{
						armourEquipment = inventory[i];
						inventory.erase(inventory.begin()+i);					// 인벤토리에서 제거
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
		damage *= 2;			// 크리티컬시 데미지 두 배
	}
	
	return damage;
}


void Character::buyItem(Item* item)											//아이템 구매
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
		
		if (item->getItemID() == 2) // 아이템이 포션인 경우
		{
			potionBag.push_back(item);
		}
		else if (item->getItemID() == 0 || item->getItemID() == 1) // 아이템이 무기나 방어구인 경우
		{
			addEquipment(item, item->getItemID());
		}
		else
		{
			cout << "error" << endl;
		}
	}
}

void Character::sellItem(Item* item)							// 아이템 판매
{
	gold += item->getPrice();									// 골드 획득

	if (item->getItemID() == 2)										//포션 제거
	{        auto potionIt = std::find(potionBag.begin(), potionBag.end(), item);
        if (potionIt != potionBag.end())
		{
            potionBag.erase(potionIt);
        }
	}
	else if (item->getItemID() == 0 || item->getItemID() == 1)		 //장비 제거 
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
			inventory.push_back(item); // 아이템을 인벤토리에 추가
		}
	}
	else
	{
		NULL;
	}

	cout << item->getItemName() << " added to bag" << endl;
}

void Character::useItem() //아이템 사용
{
	if (potionBag.empty())
	{
		cout << "potion is empty!" << endl;
	}
	else
	{
		for (int i = 0; i <= potionBag.size(); i++)
		{
			cout << i << ". " << potionBag[i]->getItemName() << endl;
		}
		int selectItem;
		cout << "Select item to use: ";
		cin >> selectItem;

		addStatus(potionBag[selectItem]); // 아이템 능력치 적용
		potionBag.erase(potionBag.begin() + selectItem);
		cout << "you used" << potionBag[selectItem]->getItemName();
	}

	//전투 후 포션 능력치 상실부분
}

void Character::addGold(int amount)
{
	gold += amount;
}

void Character::setPlayerState(State state)
{
	playerState = state;
}
