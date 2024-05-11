/*
	���� �̸�: BlockController.h
	���� ����
		- �� ��Ʈ�ѷ� Ŭ���� ����
*/

#pragma once
#ifndef __BLOCK_CONTROLLER_H__
#define __BLOCK_CONTROLLER_H__

#include "TetrisCommonDelc.h"
#include "Block.h"

// �� Ŭ������ �������� �ڷ��� ����
typedef Block* BLOCK_PTR;

// �� ��ü�� ��Ʈ���ϱ� ���� Ŭ����
class BlockController
{
private:
	BLOCK_PTR blockPtr[2] = { {} };		// �� ��ü ���� �迭
public:
	// ������
	BlockController();

	// ���� �� ��ü ����
	BLOCK_PTR MakeBlock(int blockType) const;

	// ���� �� ��ü ����
	void MakeNextBlock();

	// ���� �� ��ȯ
	BLOCK_PTR GetMainBlock() const;

	// ���� �� ��ȯ
	BLOCK_PTR GetNextBlock() const;

	// �� ��ü �� ����
	void ChangeBlock();
};

#endif // !__BLOCK_CONTROLLER_H__