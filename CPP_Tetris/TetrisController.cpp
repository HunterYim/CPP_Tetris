/*
	���� �̸�: TetrisController.cpp
	���� ����
		- ��Ʈ���� ���� ��Ʈ�ѷ� Ŭ���� ����
*/

#include "TetrisController.h"

TetrisController::TetrisController()
// �ʱ�ȭ: �� �̵� �Ұ���, 0��, timeStart�� ���� �ð�
	: isLeft(false), isRight(false), isDown(false), score(0), timeStart(clock())
{
	// ���� ���� �⺻ ������ �ʱ�ȭ
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			gameMap[i][j] = baseMap[i][j];
		}
	}
}

void TetrisController::DrawSubMap()
{
	// ���� �ڽ� ���
	for (int i = 0; i < 8; i++)
	{
		GoToxy(60, i + 9);
		cout << nextBox[i] << endl;
	}
	// ���� �ڽ� ���
	for (int i = 0; i < 7; i++)
	{
		GoToxy(60, i + 22);
		cout << scoreBox[i] << endl;
	}
}
void TetrisController::DrawMap() const
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		GoToxy(20, i + 9);
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (gameMap[i][j] == 2)
				cout << "��";
			else if (gameMap[i][j] == 1)
				cout << "��";
			else if (gameMap[i][j] == 0)
				cout << "  ";
		}
	}
}
void TetrisController::SetClock() { timeStart = clock(); }

bool TetrisController::IsMoveDown(BlockController& bcon)
{
	// ���� ���� x, y ��ǥ
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();
	int space;	// �� �迭�� �� ����

	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		space = bcon.GetMainBlock()->GetBottomLimit()[i];
		// �� ���� ������� �����鼭, �� ��ǥ�� �Ʒ� ĭ(+1)�� �� ������ �ƴ� ���
		if (space != -1 &&
			gameMap[y - 9 + space + 1][(x / 2) - 10 + i] != 0)
		{
			return false;
		}
	}
	return true;
}
bool TetrisController::IsMoveLeft(BlockController& bcon)
{
	// ���� ���� x, y ��ǥ
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();
	int space;	// �� �迭�� �� ����

	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		space = bcon.GetMainBlock()->GetLeftLimmit()[i];
		// �� ���� ������� �����鼭, �� ��ǥ�� ���� ĭ(-1)�� �� ������ �ƴ� ���
		if (space != -1 &&
			gameMap[y - 9 + i][(x / 2) - 10 - 1 + space] != 0)
		{
			return false;
		}
	}
	return true;
}
bool TetrisController::IsMoveRight(BlockController& bcon)
{
	// ���� ���� x, y ��ǥ
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();
	int space;	// �� �迭�� �� ����

	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		space = bcon.GetMainBlock()->GetRightLimmit()[i];
		// �� ���� ������� �����鼭, �� ��ǥ�� ������ ĭ(+1)�� �� ������ �ƴ� ���
		if (space != -1 &&
			gameMap[y - 9 + i][(x / 2) - 10 + 1 + space] != 0)
		{
			return false;
		}
	}
	return true;
}
bool TetrisController::IsRotate(BlockController& bcon)
{
	// ���� ���� x, y ��ǥ
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();
	// ���� ���� �� �迭 ����
	int** blockArr = bcon.GetMainBlock()->GetBlockArr();
	// �ӽ� ������ �迭 ����
	int tempArr[BLOCK_SIZE][BLOCK_SIZE];

	// �迭 90�� ȸ��
	for (int i = 0; i < BLOCK_SIZE; i++)
		for (int j = 0; j < BLOCK_SIZE; j++)
			tempArr[i][j] = blockArr[BLOCK_SIZE - j - 1][i];

	// ȸ������ ���� �� ��ġ�� ���̳� ���� �ִ� ���
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
		{
			if (tempArr[i][j] == 1)
			{
				if (gameMap[y - 10 + i][(x / 2) - 10 + j] == 1 ||
					gameMap[y - 10 + i][(x / 2) - 10 + j] == 2)
					return false;
			}
		}
	}
}

void TetrisController::StackBlock(BlockController& bcon, int num)
{
	// ���� ���� x, y ��ǥ
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();

	// ���� ��ġ�� �ش��ϴ� ���� �� ĭ�� ���� �����ϰ� 1�� ����
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
		{
			if (bcon.GetMainBlock()->GetBlock(i, j) == 1)
			{
				gameMap[y - num + i][(x / 2) - 10 + j] = 1;
			}
		}
	}
}
void TetrisController::StackingBock(BlockController& bcon, int num)
{
	// �� ����, ���� ����� �� ���ο� �� ���
	StackBlock(bcon, num);
	CalScore();
	PrintScore();
	DrawMap();

	// ���ο� �� ����/��� �� ���� �� ����
	bcon.ChangeBlock();
	bcon.GetMainBlock()->DrawBlock();
}

int TetrisController::LineCheck()
{
	int blockSum;		// �ش� �� ���� ����
	int lineSum = 0;	// Ŭ������ �� ���� Ȯ��
	// �� ���� �ٸ��� �Ʒ����� Ȯ��
	for (int i = MAP_HEIGHT - 1; i > 0; i--)
	{
		blockSum = 0;	// �� ���� ���� Ȯ���ϱ� �� blockSum �ʱ�ȭ

		// �� ���� �ٿ��� 1�� �ε������� 10�� �ε�������(���� ������ ��) �� Ȯ��
		for (int j = 1; j < MAP_WIDTH - 1; j++)
		{
			// �ش� ĭ�� ���� ��
			if (gameMap[i][j] == 1)
			{
				blockSum += 1;
			}
		}

		// �ش� ���� ���� 10�� ��, �� �� á�� ��
		if (blockSum == 10)
		{
			// ���� ��� ĭ�� �Ʒ��� �� ĭ�� �̵�
			for (int k = 1; k < MAP_WIDTH - 1; k++)
			{
				for (int l = i; l > 0; l--)
				{
					gameMap[l][k] = gameMap[l - 1][k];
				}
			}
			lineSum++;
			i++;	// �Ʒ��� �� ĭ�� �̵��߱� ������ �ε��� i���� ���� ���� �ٽ� Ȯ��
		}
	}

	return lineSum;
}
void TetrisController::CalScore()
{
	// ���� ����� �� ���� ����/���
	switch (LineCheck())
	{
	case 0:
		break;
	case 1:
		score += 100;
		break;
	case 2:
		score += 500;
		break;
	case 3:
		score += 1500;
		break;
	case 4:
		score += 4000;
		break;
	default:
		break;
	}
}
void TetrisController::PrintScore()
{
	if (score < 10)				GoToxy(68, 25);
	else if (score < 1000)		GoToxy(67, 25);
	else if (score < 10000)		GoToxy(66, 25);
	else if (score < 1000000)	GoToxy(65, 25);
	else if (score < 100000000) GoToxy(64, 25);
	cout << score;
}

bool TetrisController::IsGameOver()
{
	// ���� �� ���ٱ��� ���� ä���� ���
	for (int i = 1; i < MAP_WIDTH - 1; i++)
	{
		if (gameMap[0][i] == 1)
		{
			return true;
		}
	}
	// ���ο� ���� ������ �� ���� ��
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
		{
			if (gameMap[i][j + 4] == 1)
			{
				return true;
			}
		}
	}
	return false;
}
void TetrisController::GameOver()
{
	GoToxy(9, 1);
	cout << " #####       ###  #     #  #######      #####   #     #  #######  ###### ";
	GoToxy(9, 2);
	cout << "#           #  #  ##   ##  #           #     #  #    #   #        #     #";
	GoToxy(9, 3);
	cout << "#   ###    #   #  # # # #  #######     #     #  #   #    #######  ###### ";
	GoToxy(9, 4);
	cout << "#     #   ######  #  #  #  #           #     #  #  #     #        #    # ";
	GoToxy(9, 5);
	cout << " #####   #     #  #     #  #######      #####   ###      #######  #     #";
	GoToxy(23, 7);
	cout << "�����̽� �ٸ� ������ �޴� ȭ������ �̵��մϴ�";

	while (1)
	{
		// Ű �Է�
		//int input = KeyControl();

		// �����̽� Ű
		if (KeyControl() == KEY_INPUT::SPACE) { break; }
	}
}

void TetrisController::GameMain()
{
	// ���� �ʱ� ����
	system("cls");			// ȭ�� �����
	DrawMap();				// �� ���
	DrawSubMap();			// ���� �� ���
	PrintScore();			// ���� ���� ���
	BlockController bcon;	// �� ��Ʈ�� Ŭ���� ��ü ���� (�����ڸ� ���� �� �ڵ� ����)
	SetClock();				// ���� �ð� ����

	// ���� ����
	while (1)
	{
		// �̵� ���� ���� �˻�
		isLeft = IsMoveLeft(bcon);
		isRight = IsMoveRight(bcon);
		isDown = IsMoveDown(bcon);

		// ���� ���� ���̵� ����
		// ���� �ð��� ���� �ð��� ���̰� ���� �ð��� ������ �� �ڵ� �ϰ�
		clock_t timeDiff = clock() - timeStart;

		if (score >= 0 && score < 25000 && timeDiff > 1000)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// ���� �ð� �缳��

			// ���� ������ �� ���� ��, �� ���� �׿��� �� ��
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}
		else if (score >= 25000 && score < 50000 && timeDiff > 800)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// ���� �ð� �缳��

			// ���� ������ �� ���� ��, �� ���� �׿��� �� ��
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}
		else if (score >= 50000 && score < 75000 && timeDiff > 500)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// ���� �ð� �缳��

			// ���� ������ �� ���� ��, �� ���� �׿��� �� ��
			if (!isDown)
			{
				StackingBock(bcon, 9);
			}
		}
		else if (score >= 75000 && score < 100000 && timeDiff > 350)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// ���� �ð� �缳��

			// ���� ������ �� ���� ��, �� ���� �׿��� �� ��
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}
		else if (score >= 100000 && score < 150000 && timeDiff > 200)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// ���� �ð� �缳��

			// ���� ������ �� ���� ��, �� ���� �׿��� �� ��
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}
		else if (score >= 150000 && timeDiff > 100)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// ���� �ð� �缳��

			// ���� ������ �� ���� ��, �� ���� �׿��� �� ��
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}

		// Ű �Է�
		int input = KeyControl();
		// ȸ�� �� �̵� ���� ���� Ȯ��
		// �����̽� Ű �Է�
		if (IsRotate(bcon) && input == KEY_INPUT::SPACE)
		{
			bcon.GetMainBlock()->RotateBlock();
			bcon.GetMainBlock()->DrawBlock();
		}
		// �Ʒ� Ű �Է�
		if (isDown == true && input == KEY_INPUT::DOWN)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// ���� �ð� �缳��

			// ���� ������ �� ���� ��, �� ���� �׿��� �� ��
			if (!IsMoveDown(bcon))
			{
				StackingBock(bcon, 9);
			}
		}
		// ���� Ű �Է�
		if (isLeft == true && input == KEY_INPUT::LEFT)
		{
			bcon.GetMainBlock()->MoveLeft();
		}
		// ������ Ű
		if (isRight == true && input == KEY_INPUT::RIGHT)
		{
			bcon.GetMainBlock()->MoveRight();
		}

		// ���� ���� ���� Ȯ��
		if (IsGameOver())
		{
			GameOver();	// ���� ���� ���� ���
			break;
		}
	}
}