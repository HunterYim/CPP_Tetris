/*
	���� �̸�: Block.cpp
	���� ����
		- ��Ʈ���� �� Ŭ���� ����
*/

#include "Block.h"

Block::Block(int block[BLOCK_SIZE][BLOCK_SIZE], int type) : blockType(type)
{
	// �� Ÿ�Կ� ���� ��ǥ ����
	if (blockType == BLOCK_TYPE::MAIN) { SetX(28); SetY(9); }
	else if (blockType == BLOCK_TYPE::NEXT) { SetX(65); SetY(11); }

	// ��(2���� �迭)�� �ּҰ� �Ҵ�
	blockArr = new int* [BLOCK_SIZE];
	for (int i = 0; i < BLOCK_SIZE; i++)
		blockArr[i] = new int[BLOCK_SIZE];

	// ��(2���� �迭)�� �� �� ����
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
			blockArr[i][j] = block[i][j];
	}

	// �� ��ġ�� �迭�� 1���� �迭 �Ҵ�
	bottomLimit = new int[BLOCK_SIZE];
	leftLimit = new int[BLOCK_SIZE];
	rightLimit = new int[BLOCK_SIZE];
}
Block::Block(const Block& ref) : blockType(BLOCK_TYPE::MAIN)
{
	// �� Ÿ�Կ� ���� ��ǥ ����
	if (blockType == BLOCK_TYPE::MAIN) { SetX(28); SetY(9); }
	else if (blockType == BLOCK_TYPE::NEXT) { SetX(65); SetY(11); }

	// ��(2���� �迭)�� �ּҰ� �Ҵ�
	blockArr = new int* [BLOCK_SIZE];
	for (int i = 0; i < BLOCK_SIZE; i++)
		blockArr[i] = new int[BLOCK_SIZE];

	// ��(2���� �迭)�� �� �� ����
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
			blockArr[i][j] = ref.blockArr[i][j];
	}

	// �� ��ġ�� �迭�� 1���� �迭 �Ҵ�
	bottomLimit = new int[BLOCK_SIZE];
	leftLimit = new int[BLOCK_SIZE];
	rightLimit = new int[BLOCK_SIZE];
}

void Block::SetX(int x) { xpos = x; }
void Block::SetY(int y) { ypos = y; }

int Block::GetX() { return xpos; }
int Block::GetY() { return ypos; }

int** Block::GetBlockArr() const { return blockArr; }
int Block::GetBlock(int x, int y) const { return blockArr[x][y]; }
int Block::GetBlockType() const { return blockType; }

int* Block::GetBottomLimit()
{
	// �� ���� �ϴ� ��ġ�� -1�� �ʱ�ȭ
	for (int i = 0; i < BLOCK_SIZE; i++)
		bottomLimit[i] = -1;
	// �� ������ �ϴ� ���� ��ġ�� �迭�� ����
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
		{
			if (GetBlock(j, i) == 1)
			{
				bottomLimit[i] = j;
			}
		}
	}
	return bottomLimit;
}
int* Block::GetLeftLimmit()
{
	// �� ���� ���� ��ġ�� -1�� �ʱ�ȭ
	for (int i = 0; i < BLOCK_SIZE; i++)
		leftLimit[i] = -1;
	// �� �࿡�� ���� ���� ��ġ�� �迭�� ����
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = BLOCK_SIZE - 1; j >= 0; j--)
		{
			if (GetBlock(i, j) == 1)
			{
				leftLimit[i] = j;
			}
		}
	}
	return leftLimit;
}
int* Block::GetRightLimmit()
{
	// �� ���� ������ ��ġ�� -1�� �ʱ�ȭ
	for (int i = 0; i < BLOCK_SIZE; i++)
		rightLimit[i] = -1;
	// �� �࿡�� ������ ���� ��ġ�� �迭�� ����
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
		{
			if (GetBlock(i, j) == 1)
			{
				rightLimit[i] = j;
			}
		}
	}
	return rightLimit;
}

void Block::DrawBlock() const
{
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
		{
			// �� �迭���� �ش� ��ġ�� 1, �� ���� ��� �ฦ ���
			if (GetBlock(j, i) == 1)
			{
				GoToxy(xpos + (i * 2), ypos + j);
				cout << "��";
			}
		}
	}
}
void Block::RotateBlock()
{
	int tempArr[BLOCK_SIZE][BLOCK_SIZE];	// �ӽ� ������ �迭 ����

	// �迭 90�� ȸ��
	for (int i = 0; i < BLOCK_SIZE; i++)
		for (int j = 0; j < BLOCK_SIZE; j++)
			tempArr[i][j] = blockArr[BLOCK_SIZE - j - 1][i];

	RemoveBlock();	// �� ����

	// ȸ�� �� ����
	for (int i = 0; i < BLOCK_SIZE; i++)
		for (int j = 0; j < BLOCK_SIZE; j++)
			blockArr[i][j] = tempArr[i][j];
}
void Block::RemoveBlock()
{
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
		{
			// �� �迭���� �ش� ��ġ�� 1, �� ���� ��� �ش� ��ġ�� ����("  ")�� ���
			if (GetBlock(j, i) == 1)
			{
				GoToxy(xpos + (i * 2), ypos + j);
				cout << "  ";
			}
		}
	}
}

void Block::MoveDown()
{
	RemoveBlock();
	ypos++;
	DrawBlock();
}
void Block::MoveLeft()
{
	RemoveBlock();
	xpos -= 2;
	DrawBlock();
}
void Block::MoveRight()
{
	RemoveBlock();
	xpos += 2;
	DrawBlock();
}

Block::~Block() { delete[]blockArr; }