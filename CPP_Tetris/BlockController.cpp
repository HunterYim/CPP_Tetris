/*
	���� �̸�: BlockController.cpp
	���� ����
		- �� ��Ʈ�ѷ� Ŭ���� ����
*/

#include "BlockController.h"
#include "BlockArr.h"

BlockController::BlockController()
{
	// ��ü ������ ���ÿ� �ʱ� ���� �� �� ���� �� ���� ���� �ڵ� ����
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
	// �������� ������ 0 ~ 6 ������ ����(�� ��Ʈ���� ��)�� ���� �� ���� ����
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
	// ���� ���� �Ű� ������ ����� ���� ������ ȣ��� ������ ���� ���� ���� ������ �̵�
	blockPtr[BLOCK_TYPE::MAIN] = new Block(*blockPtr[BLOCK_TYPE::NEXT]);
	// ���� ���� �� ����
	blockPtr[BLOCK_TYPE::NEXT]->RemoveBlock();
	// ���ο� ���� �� ����
	MakeNextBlock();
	// ���� �� ���
	blockPtr[BLOCK_TYPE::NEXT]->DrawBlock();
}