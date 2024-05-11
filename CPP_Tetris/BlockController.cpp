/*
	파일 이름: BlockController.cpp
	파일 설명
		- 블럭 컨트롤러 클래스 정의
*/

#include "BlockController.h"
#include "BlockArr.h"

BlockController::BlockController()
{
	// 객체 생성과 동시에 초기 다음 블럭 및 메인 블럭 생성 과정 자동 진행
	MakeNextBlock();
	ChangeBlock();
	GetMainBlock()->DrawBlock();
	GetNextBlock()->DrawBlock();
}

BLOCK_PTR BlockController::MakeBlock(int blockType) const
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 6);
	auto randNum = dist(mt);
	// 랜덤으로 생성된 0 ~ 6 까지의 숫자(각 테트리스 블럭)에 따라 블럭 랜덤 생성
	switch (randNum) {
	case 0:
		return new Block(BLOCK_ARR::IBlock, blockType);
		break;
	case 1:
		return new Block(BLOCK_ARR::JBlock, blockType);
		break;
	case 2:
		return new Block(BLOCK_ARR::LBlock, blockType);
		break;
	case 3:
		return new Block(BLOCK_ARR::OBlock, blockType);
		break;
	case 4:
		return new Block(BLOCK_ARR::SBlock, blockType);
		break;
	case 5:
		return new Block(BLOCK_ARR::TBlock, blockType);
		break;
	case 6:
		return new Block(BLOCK_ARR::ZBlock, blockType);
		break;
	}
}

void BlockController::MakeNextBlock()
{
	blockPtr[BLOCK_TYPE::NEXT] = MakeBlock(BLOCK_TYPE::NEXT);
}

BLOCK_PTR BlockController::GetMainBlock() const
{
	return blockPtr[BLOCK_TYPE::MAIN];
}

BLOCK_PTR BlockController::GetNextBlock() const
{
	return blockPtr[BLOCK_TYPE::NEXT];
}

void BlockController::ChangeBlock()
{
	// 다음 블럭을 매개 변수로 사용한 복사 생성자 호출로 기존의 다음 블럭이 메인 블럭으로 이동
	blockPtr[BLOCK_TYPE::MAIN] = new Block(*blockPtr[BLOCK_TYPE::NEXT]);
	// 기존 다음 블럭 제거
	blockPtr[BLOCK_TYPE::NEXT]->RemoveBlock();
	// 새로운 다음 블럭 생성
	MakeNextBlock();
	// 다음 블럭 출력
	blockPtr[BLOCK_TYPE::NEXT]->DrawBlock();
}