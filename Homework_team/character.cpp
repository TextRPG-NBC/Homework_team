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

void Character::displayInfo() const {											//캐릭터 정보
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << gold << endl;
}

vector<Item> Character::invenrotoryInfo() // 인벤토리 리턴  
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




void Character::addExp(int amount)												//경험치 획득
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


void Character::deleteEquipment(Item* item, int ItemID)				//장비 제거
{
	if (ItemID == 0) // 무기의 경우	
		{
		if (weaponEquipment == nullptr)	
		{
			cout << "No equipment this parts" << endl;
		}
		else if (weaponEquipment != nullptr)						 
		{
			weaponEquipment = nullptr;								//장비 초기화
		}
	}
	else if (ItemID == 1) // 방어구의 경우	
	{
		if (armourEquipment == nullptr)							
		{
			cout << "No equipment this parts" << endl;
		}
		else if (armourEquipment != nullptr)						 //방어구 초기화
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

void Character::useItem(Item* item) //아이템 사용
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
		addStatus(item); // 아이템 능력치 적용
		cout << "you used" << item->getItemName();
	}
}

void Character::addGold(int amount)
{
	gold += amount;
}