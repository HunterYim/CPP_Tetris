/*
	���� �̸�: TetrisController.h
	���� ����
		- ��Ʈ���� ���� ��Ʈ�ѷ� Ŭ���� ����
		- ��ü ���ӿ� ���� GameMain ����
*/

#pragma once
#ifndef __TETRIS_CONTROLLER_H__
#define __TETRIS_CONTROLLER_H__

#include "TetrisCommonDelc.h"
#include "GameFunc.h"
#include "BlockController.h"

// ��Ʈ���� ���� ��ü�� ��Ʈ���ϱ� ���� Ŭ����
class TetrisController
{
private:
	// ��Ʈ���� �⺻ ��
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
	// ���� ��µǴ� ���� ��
	int gameMap[MAP_HEIGHT][MAP_WIDTH];
	// �����: ���� �� �ڽ�, ���� �ڽ�
	char nextBox[8][25] = {
		{"      NEXT"},
		{"��            ��"},
		{"��            ��"},
		{"��            ��"},
		{"��            ��"},
		{"��            ��"},
		{"��            ��"},
		{"�âââââââ�"},
	};
	char scoreBox[7][25] = {
		{"    ScoreBox"},
		{"��            ��"},
		{"��            ��"},
		{"��            ��"},
		{"��            ��"},
		{"��            ��"},
		{"�âââââââ�"}
	};
	bool isLeft;		// ���� �̵� ���� ����
	bool isRight;		// ������ �̵� ���� ����
	bool isDown;		// �Ʒ��� �̵� ���� ����
	int score;			// ����
	clock_t timeStart;	// �� �ڵ� �ϰ� �ð� Ȯ�ο� clock_t Ÿ�� ����
public:
	// ������
	TetrisController();

	// ���� �� ���
	void DrawSubMap();
	// �� ���
	void DrawMap() const;
	// �ð� �� ����
	void SetClock();

	// �Ʒ��� �̵� ���� ���� Ȯ��
	bool IsMoveDown(BlockController& bcon);
	// ���� �̵� ���� ���� Ȯ��
	bool IsMoveLeft(BlockController& bcon);
	// ������ �̵� ���� ���� Ȯ��
	bool IsMoveRight(BlockController& bcon);
	// ȸ�� ���� ���� Ȯ��
	bool IsRotate(BlockController& bcon);

	// �� ����
	void StackBlock(BlockController& bcon, int num);
	// �� ���� ����
	void StackingBock(BlockController& bcon, int num);

	// ���� �����
	int LineCheck();
	// ���� ���
	void CalScore();
	// ���� ���
	void PrintScore();

	// ���� ���� ���� Ȯ��
	bool IsGameOver();
	// ���� ����
	void GameOver();

	// ���� ����
	void GameMain();
};

#endif // !__TETRIS_CONTROLLER_H__