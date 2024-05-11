/*
	파일 이름: TetrisMenu.h
	파일 설명
		- 테트리스 메뉴 클래스 선언
*/

#pragma once
#ifndef __TETRIS_MENU_H__
#define __TETRIS_MENU_H__

#include "TetrisCommonDelc.h"
#include "GameFunc.h"

// 게임 시작 시 메뉴창 설정 클래스
class TetrisMenu
{
private:
	int x;	// x 좌표
	int y;	// y 좌표
public:
	// 생성자: x, y 좌표의 위치를 초기화
	TetrisMenu();

	// 게임 시작 및 초기 설정
	void GameInit();

	// 제목 출력
	void DrawTitle();

	// 메뉴 출력
	void DrawMenu();

	// 메뉴 선택
	int SelectMenu();

	// 게임 정보
	void TetrisInfo();
};

#endif // !__TETRIS_MENU_H__