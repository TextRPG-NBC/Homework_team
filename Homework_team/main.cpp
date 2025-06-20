#include "CommonInclude.h"
#include "GameManager.h"
#include "character.h"

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

	Character* Player = new Character(PlayerName, 1, 0, 0, 0, {});
	
	while (1) {
		system("cls");
		// 전투하기 (10레벨 달성 시, 보스전)
		bool IsCharacterDead = GM.battle(Player);

		// 1. 전투 승리 -> 상점 시스템 -> 다음 전투
		if (!IsCharacterDead) 
		{
			system("pause");
		}
		else // 2. 캐릭터 사망 -> 게임 종료
		{
			cout << Player->name << "가 사망했습니다. 게임 오버!" << endl;
			break;
		}
	}
	
	
	delete Player;

	return 0;
}