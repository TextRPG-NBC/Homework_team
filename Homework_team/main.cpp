#include "CommonInclude.h"
#include "GameManager.h"
#include "character.h"

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

	Character* Player = new Character(PlayerName, 1, 0, 0, 0, {});
	
	while (1) {
		system("cls");
		// �����ϱ� (10���� �޼� ��, ������)
		bool IsCharacterDead = GM.battle(Player);

		// 1. ���� �¸� -> ���� �ý��� -> ���� ����
		if (!IsCharacterDead) 
		{
			system("pause");
		}
		else // 2. ĳ���� ��� -> ���� ����
		{
			cout << Player->name << "�� ����߽��ϴ�. ���� ����!" << endl;
			break;
		}
	}
	
	
	delete Player;

	return 0;
}