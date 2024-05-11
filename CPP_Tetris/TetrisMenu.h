/*
	���� �̸�: TetrisMenu.h
	���� ����
		- ��Ʈ���� �޴� Ŭ���� ����
*/

#pragma once
#ifndef __TETRIS_MENU_H__
#define __TETRIS_MENU_H__

#include "TetrisCommonDelc.h"
#include "GameFunc.h"

// ���� ���� �� �޴�â ���� Ŭ����
class TetrisMenu
{
private:
	int x;	// x ��ǥ
	int y;	// y ��ǥ
public:
	// ������: x, y ��ǥ�� ��ġ�� �ʱ�ȭ
	TetrisMenu();

	// ���� ���� �� �ʱ� ����
	void GameInit();

	// ���� ���
	void DrawTitle();

	// �޴� ���
	void DrawMenu();

	// �޴� ����
	int SelectMenu();

	// ���� ����
	void TetrisInfo();
};

#endif // !__TETRIS_MENU_H__