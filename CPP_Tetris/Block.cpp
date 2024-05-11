/*
	파일 이름: Block.cpp
	파일 설명
		- 테트리스 블럭 클래스 정의
*/

#include "Block.h"

Block::Block(int block[BLOCK_SIZE][BLOCK_SIZE], int type) : blockType(type)
{
	// 블럭 타입에 따라 좌표 설정
	if (blockType == BLOCK_TYPE::MAIN) { SetX(28); SetY(9); }
	else if (blockType == BLOCK_TYPE::NEXT) { SetX(65); SetY(11); }

	// 블럭(2차원 배열)에 주소값 할당
	blockArr = new int* [BLOCK_SIZE];
	for (int i = 0; i < BLOCK_SIZE; i++)
		blockArr[i] = new int[BLOCK_SIZE];

	// 블럭(2차원 배열)에 블럭 값 복사
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
			blockArr[i][j] = block[i][j];
	}

	// 블럭 위치값 배열에 1차원 배열 할당
	bottomLimit = new int[BLOCK_SIZE];
	leftLimit = new int[BLOCK_SIZE];
	rightLimit = new int[BLOCK_SIZE];
}
Block::Block(const Block& ref) : blockType(BLOCK_TYPE::MAIN)
{
	// 블럭 타입에 따라 좌표 설정
	if (blockType == BLOCK_TYPE::MAIN) { SetX(28); SetY(9); }
	else if (blockType == BLOCK_TYPE::NEXT) { SetX(65); SetY(11); }

	// 블럭(2차원 배열)에 주소값 할당
	blockArr = new int* [BLOCK_SIZE];
	for (int i = 0; i < BLOCK_SIZE; i++)
		blockArr[i] = new int[BLOCK_SIZE];

	// 블럭(2차원 배열)에 블럭 값 복사
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
			blockArr[i][j] = ref.blockArr[i][j];
	}

	// 블럭 위치값 배열에 1차원 배열 할당
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
	// 각 열의 하단 위치를 -1로 초기화
	for (int i = 0; i < BLOCK_SIZE; i++)
		bottomLimit[i] = -1;
	// 각 열에서 하단 블럭의 위치를 배열에 저장
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
	// 각 행의 왼쪽 위치를 -1로 초기화
	for (int i = 0; i < BLOCK_SIZE; i++)
		leftLimit[i] = -1;
	// 각 행에서 왼쪽 블럭의 위치를 배열에 저장
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
	// 각 행의 오른쪽 위치를 -1로 초기화
	for (int i = 0; i < BLOCK_SIZE; i++)
		rightLimit[i] = -1;
	// 각 행에서 오른쪽 블럭의 위치를 배열에 저장
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
			// 블럭 배열에서 해당 위치가 1, 즉 블럭인 경우 □를 출력
			if (GetBlock(j, i) == 1)
			{
				GoToxy(xpos + (i * 2), ypos + j);
				cout << "□";
			}
		}
	}
}
void Block::RotateBlock()
{
	int tempArr[BLOCK_SIZE][BLOCK_SIZE];	// 임시 저장할 배열 선언

	// 배열 90도 회전
	for (int i = 0; i < BLOCK_SIZE; i++)
		for (int j = 0; j < BLOCK_SIZE; j++)
			tempArr[i][j] = blockArr[BLOCK_SIZE - j - 1][i];

	RemoveBlock();	// 블럭 제거

	// 회전 블럭 복사
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
			// 블럭 배열에서 해당 위치가 1, 즉 블럭인 경우 해당 위치에 공백("  ")을 출력
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