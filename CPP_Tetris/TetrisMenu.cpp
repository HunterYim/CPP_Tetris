/*
	파일 이름: TetrisMenu.cpp
	파일 설명
		- 테트리스 메뉴 클래스 정의
*/

#include "TetrisMenu.h"

TetrisMenu::TetrisMenu() : x(40), y(22) { }

void TetrisMenu::GameInit()
{
	system("cls");
	DrawTitle();
	DrawMenu();
}

void TetrisMenu::DrawTitle()
{
	GoToxy(0, 8);
	cout << "               =============================================================" << endl;
	GoToxy(0, 10);
	cout << "                  #####     #####     #####     ####      #####      ####  " << endl;
	cout << "                    #       #           #       #   #       #       #      " << endl;
	cout << "                    #       #####       #       ####        #        ###   " << endl;
	cout << "                    #       #           #       #  #        #           #  " << endl;
	cout << "                    #       #####       #       #   #     #####     ####   " << endl;
	GoToxy(0, 16);
	cout << "               =============================================================" << endl;
}

void TetrisMenu::DrawMenu()
{
	GoToxy(x - 2, y);
	cout << "> 게 임 시 작" << endl;
	GoToxy(x, y + 4);
	cout << "게 임 정 보" << endl;
	GoToxy(x, y + 8);
	cout << "   종 료   " << endl << endl << endl << endl;
}

int TetrisMenu::SelectMenu()
{
	// 선택 입력 대기 루프
	while (1)
	{
		switch (KeyControl())		// 키가 입력될 경우
		{
		case KEY_INPUT::UP:		// UP 키가 눌렸을 경우
		{
			if (y > 22)
			{
				GoToxy(x - 2, y);
				cout << " ";
				y -= 4;
				GoToxy(x - 2, y);
				cout << ">";
			}
			break;
		}
		case KEY_INPUT::DOWN:	// DOWN 키가 눌렸을 경우
		{
			if (y < 30)
			{
				GoToxy(x - 2, y);
				cout << " ";
				y += 4;
				GoToxy(x - 2, y);
				cout << ">";
			}
			break;
		}
		case KEY_INPUT::SPACE:	// SPACE 키가 눌렸을 경우
		{
			return (y - 22) / 4;
		}
		}
	}
}

void TetrisMenu::TetrisInfo()
{
	system("cls");
	GoToxy(0, 6);
	cout << "                                       [조 작 방 법]";
	cout << endl << endl << endl;
	cout << "                     이동: 방향키 or W, A, S, D 사용   |   선택: SPACE    ";
	cout << endl << endl << endl << endl << endl << endl;
	cout << "             스 페 이 스 바 를   누 르 면   메 인 화 면 으 로   이 동 합 니 다";

	// 스페이스 입력 대기
	while (1)
	{
		if (KeyControl() == KEY_INPUT::SPACE)
		{
			y = 22;
			break;
		}
	}
}