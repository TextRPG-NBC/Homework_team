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

void Character::displayInfo() const {											//캐릭터 정보
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Critical Rate: " << criticalRate << "%" << endl;
	cout << "Have money : " << gold << endl;

	if (armourEquipment.empty()) {
		cout << "Armour is empty!" << endl;									//장비가 없을 경우
	}
	else {
		for (Item* item : armourEquipment) {
			cout << "equipment Item: " << item->getItemName() << endl;				 //보유한 장비 출력
		}

	if (weaponEquipment.empty()) {
		cout << "Weapon is empty!" << endl;									//장비가 없을 경우
	}

	else 
		{
		for (Item* item : weaponEquipment)
			cout << "equipment Item: " << item->getItemName() << endl;				 //보유한 장비 출력
		}
	
	if (inventory.empty()) {
		cout << "Inventory is empty!" << endl;									//장비가 없을 경우
	}

	else {
		for (Item* item : inventory) {
			cout << "Inventory Item: " << item->getItemName() << endl;				 //보유한 장비 출력
		}
	}

	if (potionBag.empty()) {													//소모품이 없을 경우
		cout << "potion is empty!" << endl;
	}

	else {
		for (Item* item : potionBag) {
			cout << "Potion Item: " << item->getItemName() << endl;				 //보유한 소모품 출력
		}
	}


void Character::gainExp(int amount)												//경험치 획득
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

void Character::addEquipment(Item* item, int ItemID)							 // 0: 무기, 1: 방어구
{
	if (equipment[ItemID] == NULL)
	{
		equipment.at(ItemID) = item;										//새 장비 장착
		addStatus(item);													//새 장비 능력치 적용
		cout << "you equip Weapon" << item->getItemName() << endl;
	}
	else
	{
		deleteEquipment(equipment[ItemID], ItemID);							//구 장비 제거	
		removeStatus(equipment[ItemID]);									//구 장비 능력치 제거
		cout << "equiped " << equipment[ItemID]->getItemName() << "put in bag" << endl;
		cout << "now you equip " << item->getItemName() << endl;
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
		inventory.push_back(item);											 //구매한 아이템을 인벤토리에 추가
	}
}

void Character::sellItem(Item* item)										 // 아이템 판매
{
	gold += item->getPrice();
	if (item->getItemID() == 2) // 아이템이 nullptr인 경우 처리
	{
		PotionBag.erase(
			remove_if(PotionBag.begin(), PotionBag.end(), [](const Item& item) {}));
	}
	else if (item->getItemID() == 0 || 1) // 아이템이 nullptr인 경우 처리
	{
		inventory.erase(
			remove_if(inventory.begin(), inventory.end(),
				[item](Item* i) { return i == item; }),
			inventory.end()
		);
	}
	else
	{
		NULL; // 아이템이 nullptr인 경우 처리
	}
}
*/


void Character::addItem(Item* item)
{
	if (item->getItemID() == 2) // 아이템이 nullptr인 경우 처리
	{
		potionBag.push_back(item);
	}
	else if (item->getItemID() == 0 || 1) // 아이템이 nullptr인 경우 처리
	{
		int itemIdCheck = item->getItemID();
		if (itemIdCheck){
			addEquipment(item, itemIdCheck);
		inventory.push_back(item); // 아이템을 인벤토리에 추가
		}
	}
	else
	{
		NULL; // 아이템이 nullptr인 경우 처리
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

		equipment.erase(equipment.begin() + selectItem);
		addStatus(item); // 아이템 능력치 적용
		cout << "you used" << item->getItemName();
	}
}

void Character::addGold(int amount)
{
	gold += amount;
}
