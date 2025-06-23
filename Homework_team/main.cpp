#include "CommonInclude.h"
#include "GameManager.h"
#include "character.h"
#include "Shop.h"

using namespace std;

int main()
{
	srand(time(NULL));
	GameManager GM;

	// 캐릭터 생성 (이름 입력)
	string PlayerName;
	cout << "캐릭터 이름을 입력하세요: ";
	getline(cin, PlayerName);

	do {
		if (PlayerName != "")	// 입력 유효성 검사
			break;
		cin.ignore();
		cout << "캐릭터 이름을 재입력하세요: ";
	} while(getline(cin, PlayerName));

	Character* Player = new Character(PlayerName);
	Shop ShopSystem;

	while (1) {
		system("cls");
		// 전투하기
		bool IsCharacterDead = GM.battle(Player);

		// 1. 전투 승리 -> 상점 시스템 -> 다음 전투
		if (!IsCharacterDead) 
		{
			string IsShopping;
			// 상점 시스템
			cout << "상점을 방문하시겠습니까? (Y/N): ";
			cin >> IsShopping;

			if (IsShopping == "Y" || IsShopping == "y")
			{
				// 구매 가능한 아이템 출력
				ShopSystem.displayItems();

				// 캐릭터 보유 골드 출력
				cout << "골드: " << Player->getGold() << "\n";
				
				// 구매할 아이템 번호 선택
				int BuyItemNumber = 0;
				cout << "구매할 아이템 번호를 선택하세요(0:넘어가기): ";
				cin >> BuyItemNumber;

				if (BuyItemNumber != 0) 
				{
					ShopSystem.buyItem(BuyItemNumber, Player);
				}
			}

			system("pause");
		}
		else // 2. 캐릭터 사망 -> 게임 종료
		{
			cout << Player->getName() << "가 사망했습니다. 게임 오버!" << endl;
			break;
		}
	}
	
	
	delete Player;

	return 0;
}