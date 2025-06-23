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

void Character::displayInfo() const {											//캐릭터 정보
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << exp << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
    cout << "Critical Rate: " << criticalRate << "%" << endl;
    cout << "Have money : " << gold << endl;

	if (equipment.empty()) {
		cout << "equipment is empty!" << endl;									//장비가 없을 경우
	}
	else {
		for (Item* item : inventory) {
			cout << "equipment Item: " << item->itemName << endl;				 //보유한 장비 출력
		}
	}

	if (inventory.empty()) {
		cout << "Inventory is empty!" << endl;									//장비가 없을 경우
	} else {
		for (Item* item : inventory) {
			cout << "Inventory Item: " << item->itemName << endl;				 //보유한 장비 출력
		}
	}
	
	if (PotionBag.empty()) {													//소모품이 없을 경우
		cout << "potion is empty!" << endl;
	}
	else {
		for (Item* item : PotionBag) {
			cout << "Potion Item: " << item->itemName << endl;				 //보유한 소모품 출력
		}
	}
}


void Character::gainExp(int amount)												//경험치 획득
{
	exp += amount;
	cout << name << amount << " exp points up!" << endl;
	levelUp();
}

void Character::levelUp()														//레벨업
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
	int damage = attackPower;													//공격력 계산
	if (rand() % 100 < criticalRate) {											//크리티컬 확률 적용
		damage *= 2;															//크리티컬 히트 시 데미지 2배
		cout << name << " landed a critical hit!" << endl;
	}
	////////////////////
	target->takeDamage(damage);												//대상에게 데미지 적용
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

void Character::addEquipment(Item* item, int ItemID)							 // 0: 무기, 1: 방어구
{
	if (equipment[ItemID] == NULL)
	{
		equipment.at(ItemID) = item;										//새 장비 장착
		addStatus(item);													//새 장비 능력치 적용
		cout << "you equip Weapon" << item->itemName << endl;
	}
	else
	{
		deleteEquipment(equipment[ItemID], ItemID);							//구 장비 제거	
		removeStatus(equipment[ItemID]);									//구 장비 능력치 제거
		cout << "equiped " << equipment[ItemID]->itemName<< "put in bag" << endl;
		cout << "now you equip " << item->itemName << endl;
		equipment.at(ItemID) = item;										//새 장비 장착
		addStatus(item);													//새 장비 능력치 적용 장착									
	}
}


void Character::deleteEquipment(Item* item, int position)					//장비 해제
{
	if (equipment[position] == NULL)										 //장비가 비어있으면 아무것도 하지 않음
	{
		cout << "No equipment this parts" << endl;
	}
	else if (equipment[position] == item)									 //장비가 존재하면 인벤토리에 추가
	{
		inventory.push_back(equipment[position]);							//인벤토리에 창작했던 장비 추가		
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


void Character::buyItem(Item* item)											//아이템 구매
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
		inventory.push_back(item);											 //구매한 아이템을 인벤토리에 추가
	}
}

void Character::sellItem(Item* item)										 // 아이템 판매
{
    gold += item->price;
	if (item->itemID == 3) // 아이템이 nullptr인 경우 처리
	{
		PotionBag.erase(
			remove_if(PotionBag.begin(), PotionBag.end(), [](const Item& item) {}));
	}
	else if (item->itemID == 0 || 1) // 아이템이 nullptr인 경우 처리
	{
		inventory.push_back(item); // 아이템을 인벤토리에 추가
		inventory.erase(
			remove_if(inventory.begin(), inventory.end(), [](const Item& item) {}));
	}
	else
	{
		NULL; // 아이템이 nullptr인 경우 처리
	}
}

void Character::getItem(Item* item)
{
	if (item->itemID == 3) // 아이템이 nullptr인 경우 처리
	{
		PotionBag.push_back(item);
	}
	else if (item->itemID == 0 || 1) // 아이템이 nullptr인 경우 처리
	{	
		inventory.push_back(item); // 아이템을 인벤토리에 추가
	}
	else
	{
		NULL; // 아이템이 nullptr인 경우 처리
	}
	
	cout << item->itemName << " added to bag" << endl;
}

void Character::useItem(Item* item) //아이템 사용
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
		addStatus(item); // 아이템 능력치 적용
		cout << "you used" << item->itemName;
	}
}

void Character::addGold(int amount)
{
	gold += amount;
}


