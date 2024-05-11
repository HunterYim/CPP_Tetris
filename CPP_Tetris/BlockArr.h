/*
	���� �̸�: BlockArr.h
	���� ����
		- ��Ʈ���� �� ���� ���� 2���� �迭�� namespace ����
*/

#pragma once
#ifndef __BLOBK_ARR_H__
#define __BLOCK_ARR_H__

#include "TetrisCommonDelc.h"

namespace BLOCK_ARR
{
	int IBlock[BLOCK_SIZE][BLOCK_SIZE] = {
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 0, 0}
	};
	int JBlock[BLOCK_SIZE][BLOCK_SIZE] = {
		{0, 0, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 1, 1, 0}
	};
	int LBlock[BLOCK_SIZE][BLOCK_SIZE] = {
		{0, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 1, 0}
	};
	int OBlock[BLOCK_SIZE][BLOCK_SIZE] = {
		{0, 0, 0, 0},
		{0, 1, 1, 0},
		{0, 1, 1, 0},
		{0, 0, 0, 0}
	};
	int SBlock[BLOCK_SIZE][BLOCK_SIZE] = {
		{0, 0, 0, 0},
		{0, 1, 1, 0},
		{1, 1, 0, 0},
		{0, 0, 0, 0}
	};
	int TBlock[BLOCK_SIZE][BLOCK_SIZE] = {
		{0, 0, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 0, 0},
		{0, 0, 0, 0}
	};
	int ZBlock[BLOCK_SIZE][BLOCK_SIZE] = {
		{0, 0, 0, 0},
		{1, 1, 0, 0},
		{0, 1, 1, 0},
		{0, 0, 0, 0}
	};
}

#endif // !__BLOBK_ARR_H__