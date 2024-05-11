/*
	���� �̸�: GameFunc.cpp
	���� ����
		- ���ӿ� �ʿ��� ���� �Լ� ����
*/

#include "GameFunc.h"

void GoToxy(int x, int y)
{
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandler, pos);
}

int KeyControl()
{
	// Ű���� �Է��� �����Ǿ��� ��
	if (_kbhit() > 0)
	{
		char input = _getch();

		// �Է� Ű�� ���� ���� ��ȯ
		if (input == 'w' || input == 'W' || input == 72)
			return KEY_INPUT::UP;
		else if (input == 's' || input == 'S' || input == 80)
			return KEY_INPUT::DOWN;
		else if (input == 'a' || input == 'A' || input == 75)
			return KEY_INPUT::LEFT;
		else if (input == 'd' || input == 'D' || input == 77)
			return KEY_INPUT::RIGHT;
		else if (input == 32)
			return KEY_INPUT::SPACE;
	}
}

void SettingConsole()
{
	// �ܼ�â �̸� ����
	SetConsoleTitle("T E T R I S");

	// �ܼ�â ũ�� ����
	system("mode con cols=91 lines=40");

	// Ŀ�� �����
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}