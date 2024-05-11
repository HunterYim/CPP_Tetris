/*
	파일 이름: Block.h
	파일 설명
		- 테트리스 블럭 클래스 선언
*/

#pragma once
#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "TetrisCommonDelc.h"
#include "GameFunc.h"

class Block
{
private:
	int** blockArr;		// 블럭 배열
	int blockType;		// 블럭 타입
	int xpos = 0;		// x 좌표
	int ypos = 0;		// y 좌표
	int* bottomLimit;	// 블럭 하단 위치 반환
	int* leftLimit;		// 블럭 왼쪽 위치 반환
	int* rightLimit;	// 블럭 오른쪽 위치 반환
public:
	// 생성자
	Block(int block[BLOCK_SIZE][BLOCK_SIZE], int type);
	// 복사 생성자
	Block(const Block& ref);

	// x 좌표 설정
	void SetX(int x);
	// y 좌표 설정
	void SetY(int y);

	// x 좌표 반환
	int GetX();
	// y 좌표 반환
	int GetY();

	// 배열 반환
	int** GetBlockArr() const;
	// 블럭 값 반환
	int GetBlock(int x, int y) const;
	// 타입 반환
	int GetBlockType() const;

	// 하단 위치 배열 반환
	int* GetBottomLimit();
	// 왼쪽 위치 배열 반환
	int* GetLeftLimmit();
	// 오른쪽 위치 배열 반환
	int* GetRightLimmit();

	// 블럭 출력
	void DrawBlock() const;
	// 블럭 회전
	void RotateBlock();
	// 블럭 지우기
	void RemoveBlock();

	// 블럭 아래쪽 이동
	void MoveDown();
	// 블럭 왼쪽 이동
	void MoveLeft();
	// 블럭 오른쪽 이동
	void MoveRight();

	// 소멸자
	~Block();
};

#endif // !__BLOCK_H__