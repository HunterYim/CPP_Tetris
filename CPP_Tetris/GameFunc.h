/*
	���� �̸�: GameFunc.h
	���� ����
		- ���ӿ� �ʿ��� ���� �Լ� ����
*/

#pragma once
#ifndef __GAME_FUNC_H__
#define __GAME_FUNC_H__

#include "TetrisCommonDelc.h"

// �ܼ�â Ŀ�� ��ǥ �̵�
void GoToxy(int x, int y);

// Ű���� Ű �Է� ��ȯ
int KeyControl();

// �ܼ�â ����
void SettingConsole();

#endif // !__GAME_FUNC_H__