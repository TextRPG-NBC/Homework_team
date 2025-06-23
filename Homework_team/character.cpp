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

void Character::displayInfo() const { //캐릭터 정보
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << exp << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
    cout << "Critical Rate: " << criticalRate << "%" << endl;
    cout << "Have money : " << gold << endl;

	if (inventory.empty()) {
		cout << "Inventory is empty!" << endl; //소모품이 없을 경우
	} else {
		for (Item* item : inventory) {
			cout << "Inventory Item: " << item->itemName << endl; //보유한 장비 출력
		}
	}
	
	if (equipment.empty()) {
		cout << "Inventory is empty!" << endl; //소모품이 없을 경우
	}
	else {
		for (Item* item : equipment) {
			cout << "Inventory Item: " << item->itemName << endl; //보유한 장비 출력
		}
	}
}


void Character::gainExp(int amount) //경험치 획득
{
	exp += amount;
	cout << name << amount << " exp points up!" << endl;
	levelUp();
}

void Character::levelUp() //레벨업
{
	if (exp >= 100) {
		exp = 0;
		level++;
		health = 180 + (level * 20);
		attackPower = 25 + (level * 5);

		cout << name << " is level up! current level : " << level << endl;
	}
}

void Character::takeDamage(int damage)
{
	if (health - damage < 0)
	{
		health = 0;
	}
	else
	{
		health -= damage;
	}
}

void Character::addEquipment(Item* item)
{
	equipment.push_back(item);
	attackPower += item->attackPower_attribute;
	health += item->health_attribute;
	criticalRate += item->critRate_attribute;
	cout << item->itemName << " added to equipment." << endl;
}


void Character::unEquipment(Item* item) //장비 해제
{
	for (auto it = equipment.begin(); it != equipment.end(); ++it)
	{
		if (*it == item) //아이템이 장비에 있는지 확인
		{
			equipment.erase(it);
			attackPower -= item->attackPower_attribute;
			health -= item->health_attribute;
			criticalRate -= item->critRate_attribute;
			cout << item->itemName << " removed from equipment." << endl;
			return;
		}
	}
}

void Character::buyItem(Item* item) //아이템 구매
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
	}
}

void Character::addItem(Item* item) //아이템 추가
{
	inventory.push_back(item);
	cout << item->itemName << " added to inventory." << endl;
}

void Character::sellItem(Item* item) // 아이템 판매
{
	gold += item->price;
	unEquipment(item);
}


void Character::useItem(Item* item) //아이템 사용
{
	if (inventory.empty())
	{
		cout << "Inventory is empty!" << endl;
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
		//사용 후 제거 기능 추가 필요

		
	}
}

void Character::addGold(int amount)
{
	gold += amount;
}


