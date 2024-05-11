/*
	���� �̸�: TetrisMenu.cpp
	���� ����
		- ��Ʈ���� �޴� Ŭ���� ����
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
	cout << "> �� �� �� ��" << endl;
	GoToxy(x, y + 4);
	cout << "�� �� �� ��" << endl;
	GoToxy(x, y + 8);
	cout << "   �� ��   " << endl << endl << endl << endl;
}

int TetrisMenu::SelectMenu()
{
	// ���� �Է� ��� ����
	while (1)
	{
		switch (KeyControl())		// Ű�� �Էµ� ���
		{
		case KEY_INPUT::UP:		// UP Ű�� ������ ���
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
		case KEY_INPUT::DOWN:	// DOWN Ű�� ������ ���
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
		case KEY_INPUT::SPACE:	// SPACE Ű�� ������ ���
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
	cout << "                                       [�� �� �� ��]";
	cout << endl << endl << endl;
	cout << "                     �̵�: ����Ű or W, A, S, D ���   |   ����: SPACE    ";
	cout << endl << endl << endl << endl << endl << endl;
	cout << "             �� �� �� �� �� ��   �� �� ��   �� �� ȭ �� �� ��   �� �� �� �� ��";

	// �����̽� �Է� ���
	while (1)
	{
		if (KeyControl() == KEY_INPUT::SPACE)
		{
			y = 22;
			break;
		}
	}
}