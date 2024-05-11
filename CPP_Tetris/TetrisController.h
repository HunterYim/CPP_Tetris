/*
	파일 이름: TetrisController.h
	파일 설명
		- 테트리스 게임 컨트롤러 클래스 선언
		- 전체 게임에 대한 GameMain 포함
*/

#pragma once
#ifndef __TETRIS_CONTROLLER_H__
#define __TETRIS_CONTROLLER_H__

#include "TetrisCommonDelc.h"
#include "GameFunc.h"
#include "BlockController.h"

// 테트리스 게임 전체를 컨트롤하기 위한 클래스
class TetrisController
{
private:
	// 테트리스 기본 맵
	int baseMap[MAP_HEIGHT][MAP_WIDTH] = {
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	};
	// 실제 출력되는 메인 맵
	int gameMap[MAP_HEIGHT][MAP_WIDTH];
	// 서브맵: 다음 블럭 박스, 점수 박스
	char nextBox[8][25] = {
		{"      NEXT"},
		{"▣            ▣"},
		{"▣            ▣"},
		{"▣            ▣"},
		{"▣            ▣"},
		{"▣            ▣"},
		{"▣            ▣"},
		{"▣▣▣▣▣▣▣▣"},
	};
	char scoreBox[7][25] = {
		{"    ScoreBox"},
		{"▣            ▣"},
		{"▣            ▣"},
		{"▣            ▣"},
		{"▣            ▣"},
		{"▣            ▣"},
		{"▣▣▣▣▣▣▣▣"}
	};
	bool isLeft;		// 왼쪽 이동 가능 여부
	bool isRight;		// 오른쪽 이동 가능 여부
	bool isDown;		// 아래쪽 이동 가능 여부
	int score;			// 점수
	clock_t timeStart;	// 블럭 자동 하강 시간 확인용 clock_t 타입 변수
public:
	// 생성자
	TetrisController();

	// 서브 맵 출력
	void DrawSubMap();
	// 맵 출력
	void DrawMap() const;
	// 시간 재 설정
	void SetClock();

	// 아래쪽 이동 가능 여부 확인
	bool IsMoveDown(BlockController& bcon);
	// 왼쪽 이동 가능 여부 확인
	bool IsMoveLeft(BlockController& bcon);
	// 오른쪽 이동 가능 여부 확인
	bool IsMoveRight(BlockController& bcon);
	// 회전 가능 여부 확인
	bool IsRotate(BlockController& bcon);

	// 블럭 적재
	void StackBlock(BlockController& bcon, int num);
	// 블럭 적재 실행
	void StackingBock(BlockController& bcon, int num);

	// 라인 지우기
	int LineCheck();
	// 점수 계산
	void CalScore();
	// 점수 출력
	void PrintScore();

	// 게임 종료 여부 확인
	bool IsGameOver();
	// 게임 종료
	void GameOver();

	// 게임 메인
	void GameMain();
};

#endif // !__TETRIS_CONTROLLER_H__