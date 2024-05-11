/*
	파일 이름: GameFunc.h
	파일 설명
		- 게임에 필요한 공통 함수 선언
*/

#pragma once
#ifndef __GAME_FUNC_H__
#define __GAME_FUNC_H__

#include "TetrisCommonDelc.h"

// 콘솔창 커서 좌표 이동
void GoToxy(int x, int y);

// 키보드 키 입력 변환
int KeyControl();

// 콘솔창 세팅
void SettingConsole();

#endif // !__GAME_FUNC_H__