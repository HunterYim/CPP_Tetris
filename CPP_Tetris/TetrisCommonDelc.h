/*
	���� �̸�: TetrisCommonDelc.h
	���� ����
		- ���� ��� ����
		- ��� ����
		- namespace ����
		- ���� ���� �Լ� ����
*/

#pragma once
#ifndef __TETRIS_COMMON_H__
#define __TETRIS_COMMON_H__

#define _CRT_SECURE_NO_WARNINGS

// ��� ����
#define BLOCK_SIZE 4
#define MAP_WIDTH 12
#define MAP_HEIGHT 26

// ���� ��� ���� ����
#include <iostream>
#include <cstring>
#include <cstdio>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <random>
using namespace std;

// Ű���� �Է� ��
namespace KEY_INPUT
{
	enum
	{
		DOWN = 1,
		LEFT = 2,
		RIGHT = 3,
		SPACE = 4,
		UP = 5
	};
}

// ��Ʈ���� �� ���
namespace BLOCK
{
	enum
	{
		I = 0,
		J = 1,
		L = 2,
		O = 3,
		S = 4,
		T = 5,
		Z = 6
	};
}

// �� Ÿ�� ���
namespace BLOCK_TYPE
{
	enum
	{
		MAIN = 0,
		NEXT = 1
	};
}

#endif // !__TETRIS_COMMON_H__