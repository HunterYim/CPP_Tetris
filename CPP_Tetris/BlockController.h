/*
	파일 이름: BlockController.h
	파일 설명
		- 블럭 컨트롤러 클래스 선언
*/

#pragma once
#ifndef __BLOCK_CONTROLLER_H__
#define __BLOCK_CONTROLLER_H__

#include "TetrisCommonDelc.h"
#include "Block.h"

// 블럭 클래스의 포인터형 자료형 선언
typedef Block* BLOCK_PTR;

// 블럭 객체를 컨트롤하기 위한 클래스
class BlockController
{
private:
	BLOCK_PTR blockPtr[2] = { {} };		// 블럭 객체 저장 배열
public:
	// 생성자
	BlockController();

	// 랜덤 블럭 객체 생성
	BLOCK_PTR MakeBlock(int blockType) const;

	// 다음 블럭 객체 생성
	void MakeNextBlock();

	// 메인 블럭 반환
	BLOCK_PTR GetMainBlock() const;

	// 다음 블럭 반환
	BLOCK_PTR GetNextBlock() const;

	// 블럭 교체 및 제거
	void ChangeBlock();
};

#endif // !__BLOCK_CONTROLLER_H__