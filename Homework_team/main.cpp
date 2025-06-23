#include "CommonInclude.h"
#include "GameManager.h"
#include "character.h"
#include "Shop.h"

using namespace std;

int main()
{
	srand(time(NULL));
	GameManager GM;

	// ĳ���� ���� (�̸� �Է�)
	string PlayerName;
	cout << "ĳ���� �̸��� �Է��ϼ���: ";
	getline(cin, PlayerName);

	do {
		if (PlayerName != "")	// �Է� ��ȿ�� �˻�
			break;
		cin.ignore();
		cout << "ĳ���� �̸��� ���Է��ϼ���: ";
	} while(getline(cin, PlayerName));

	Character* Player = new Character(PlayerName);
	Shop ShopSystem;

	while (1) {
		system("cls");
		// �����ϱ�
		bool IsCharacterDead = GM.battle(Player);

		// 1. ���� �¸� -> ���� �ý��� -> ���� ����
		if (!IsCharacterDead) 
		{
			string IsShopping;
			// ���� �ý���
			cout << "������ �湮�Ͻðڽ��ϱ�? (Y/N): ";
			cin >> IsShopping;

			if (IsShopping == "Y" || IsShopping == "y")
			{
				// ���� ������ ������ ���
				ShopSystem.displayItems();

				// ĳ���� ���� ��� ���
				cout << "���: " << Player->getGold() << "\n";
				
				// ������ ������ ��ȣ ����
				int BuyItemNumber = 0;
				cout << "������ ������ ��ȣ�� �����ϼ���(0:�Ѿ��): ";
				cin >> BuyItemNumber;

				if (BuyItemNumber != 0) 
				{
					ShopSystem.buyItem(BuyItemNumber, Player);
				}
			}

			system("pause");
		}
		else // 2. ĳ���� ��� -> ���� ����
		{
			cout << Player->getName() << "�� ����߽��ϴ�. ���� ����!" << endl;
			break;
		}
	}
	
	
	delete Player;

	return 0;
}