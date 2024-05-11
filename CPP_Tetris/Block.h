/*
	���� �̸�: Block.h
	���� ����
		- ��Ʈ���� �� Ŭ���� ����
*/

#pragma once
#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "TetrisCommonDelc.h"
#include "GameFunc.h"

class Block
{
private:
	int** blockArr;		// �� �迭
	int blockType;		// �� Ÿ��
	int xpos = 0;		// x ��ǥ
	int ypos = 0;		// y ��ǥ
	int* bottomLimit;	// �� �ϴ� ��ġ ��ȯ
	int* leftLimit;		// �� ���� ��ġ ��ȯ
	int* rightLimit;	// �� ������ ��ġ ��ȯ
public:
	// ������
	Block(int block[BLOCK_SIZE][BLOCK_SIZE], int type);
	// ���� ������
	Block(const Block& ref);

	// x ��ǥ ����
	void SetX(int x);
	// y ��ǥ ����
	void SetY(int y);

	// x ��ǥ ��ȯ
	int GetX();
	// y ��ǥ ��ȯ
	int GetY();

	// �迭 ��ȯ
	int** GetBlockArr() const;
	// �� �� ��ȯ
	int GetBlock(int x, int y) const;
	// Ÿ�� ��ȯ
	int GetBlockType() const;

	// �ϴ� ��ġ �迭 ��ȯ
	int* GetBottomLimit();
	// ���� ��ġ �迭 ��ȯ
	int* GetLeftLimmit();
	// ������ ��ġ �迭 ��ȯ
	int* GetRightLimmit();

	// �� ���
	void DrawBlock() const;
	// �� ȸ��
	void RotateBlock();
	// �� �����
	void RemoveBlock();

	// �� �Ʒ��� �̵�
	void MoveDown();
	// �� ���� �̵�
	void MoveLeft();
	// �� ������ �̵�
	void MoveRight();

	// �Ҹ���
	~Block();
};

#endif // !__BLOCK_H__