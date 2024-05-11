/*
	파일 이름: GameFunc.cpp
	파일 설명
		- 게임에 필요한 공통 함수 정의
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
	// 키보드 입력이 감지되었을 때
	if (_kbhit() > 0)
	{
		char input = _getch();

		// 입력 키에 따른 값을 반환
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
	// 콘솔창 이름 세팅
	SetConsoleTitle("T E T R I S");

	// 콘솔창 크기 세팅
	system("mode con cols=91 lines=40");

	// 커서 숨기기
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}