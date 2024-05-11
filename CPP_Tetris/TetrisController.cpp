/*
	파일 이름: TetrisController.cpp
	파일 설명
		- 테트리스 게임 컨트롤러 클래스 정의
*/

#include "TetrisController.h"

TetrisController::TetrisController()
// 초기화: 블럭 이동 불가능, 0점, timeStart는 현재 시간
	: isLeft(false), isRight(false), isDown(false), score(0), timeStart(clock())
{
	// 게임 맵을 기본 맵으로 초기화
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
	// 다음 박스 출력
	for (int i = 0; i < 8; i++)
	{
		GoToxy(60, i + 9);
		cout << nextBox[i] << endl;
	}
	// 점수 박스 출력
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
				cout << "▣";
			else if (gameMap[i][j] == 1)
				cout << "□";
			else if (gameMap[i][j] == 0)
				cout << "  ";
		}
	}
}
void TetrisController::SetClock() { timeStart = clock(); }

bool TetrisController::IsMoveDown(BlockController& bcon)
{
	// 메인 블럭의 x, y 좌표
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();
	int space;	// 블럭 배열의 빈 공간

	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		space = bcon.GetMainBlock()->GetBottomLimit()[i];
		// 블럭 열이 비어있지 않으면서, 맵 좌표의 아래 칸(+1)이 빈 공간이 아닌 경우
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
	// 메인 블럭의 x, y 좌표
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();
	int space;	// 블럭 배열의 빈 공간

	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		space = bcon.GetMainBlock()->GetLeftLimmit()[i];
		// 블럭 행이 비어있지 않으면서, 맵 좌표의 왼쪽 칸(-1)이 빈 공간이 아닌 경우
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
	// 메인 블럭의 x, y 좌표
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();
	int space;	// 블럭 배열의 빈 공간

	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		space = bcon.GetMainBlock()->GetRightLimmit()[i];
		// 블럭 행이 비어있지 않으면서, 맵 좌표의 오른쪽 칸(+1)이 빈 공간이 아닌 경우
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
	// 메인 블럭의 x, y 좌표
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();
	// 메인 블럭의 블럭 배열 복사
	int** blockArr = bcon.GetMainBlock()->GetBlockArr();
	// 임시 저장할 배열 생성
	int tempArr[BLOCK_SIZE][BLOCK_SIZE];

	// 배열 90도 회전
	for (int i = 0; i < BLOCK_SIZE; i++)
		for (int j = 0; j < BLOCK_SIZE; j++)
			tempArr[i][j] = blockArr[BLOCK_SIZE - j - 1][i];

	// 회전했을 때의 블럭 위치에 블럭이나 벽이 있는 경우
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
	// 메인 블럭의 x, y 좌표
	int x = bcon.GetMainBlock()->GetX();
	int y = bcon.GetMainBlock()->GetY();

	// 블럭의 위치에 해당하는 맵의 각 칸을 블럭과 동일하게 1로 설정
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
	// 블럭 적재, 라인 지우기 및 새로운 맵 출력
	StackBlock(bcon, num);
	CalScore();
	PrintScore();
	DrawMap();

	// 새로운 블럭 생성/출력 및 기존 블럭 제거
	bcon.ChangeBlock();
	bcon.GetMainBlock()->DrawBlock();
}

int TetrisController::LineCheck()
{
	int blockSum;		// 해당 줄 블럭의 개수
	int lineSum = 0;	// 클리어한 줄 개수 확인
	// 각 세로 줄마다 아래부터 확인
	for (int i = MAP_HEIGHT - 1; i > 0; i--)
	{
		blockSum = 0;	// 각 세로 줄을 확인하기 전 blockSum 초기화

		// 각 세로 줄에서 1번 인덱스부터 10번 인덱스까지(벽을 제외한 맵) 블럭 확인
		for (int j = 1; j < MAP_WIDTH - 1; j++)
		{
			// 해당 칸이 블럭일 때
			if (gameMap[i][j] == 1)
			{
				blockSum += 1;
			}
		}

		// 해당 세로 줄이 10일 때, 즉 꽉 찼을 때
		if (blockSum == 10)
		{
			// 맵의 모든 칸이 아래로 한 칸씩 이동
			for (int k = 1; k < MAP_WIDTH - 1; k++)
			{
				for (int l = i; l > 0; l--)
				{
					gameMap[l][k] = gameMap[l - 1][k];
				}
			}
			lineSum++;
			i++;	// 아래로 한 칸씩 이동했기 때문에 인덱스 i부터 세로 줄을 다시 확인
		}
	}

	return lineSum;
}
void TetrisController::CalScore()
{
	// 라인 지우기 및 점수 증가/출력
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
	// 맵의 맨 윗줄까지 블럭이 채워진 경우
	for (int i = 1; i < MAP_WIDTH - 1; i++)
	{
		if (gameMap[0][i] == 1)
		{
			return true;
		}
	}
	// 새로운 블럭이 생성될 수 없을 때
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
	cout << "스페이스 바를 누르면 메뉴 화면으로 이동합니다";

	while (1)
	{
		// 키 입력
		//int input = KeyControl();

		// 스페이스 키
		if (KeyControl() == KEY_INPUT::SPACE) { break; }
	}
}

void TetrisController::GameMain()
{
	// 게임 초기 설정
	system("cls");			// 화면 지우기
	DrawMap();				// 맵 출력
	DrawSubMap();			// 서브 맵 출력
	PrintScore();			// 현재 점수 출력
	BlockController bcon;	// 블럭 컨트롤 클래스 객체 생성 (생성자를 통해 블럭 자동 생성)
	SetClock();				// 현재 시간 설정

	// 메인 루프
	while (1)
	{
		// 이동 가능 여부 검사
		isLeft = IsMoveLeft(bcon);
		isRight = IsMoveRight(bcon);
		isDown = IsMoveDown(bcon);

		// 점수 별로 난이도 조절
		// 시작 시간과 현재 시간의 차이가 일정 시간이 지나면 블럭 자동 하강
		clock_t timeDiff = clock() - timeStart;

		if (score >= 0 && score < 25000 && timeDiff > 1000)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// 시작 시간 재설정

			// 블럭이 내려갈 수 없을 때, 즉 블럭이 쌓여야 할 때
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}
		else if (score >= 25000 && score < 50000 && timeDiff > 800)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// 시작 시간 재설정

			// 블럭이 내려갈 수 없을 때, 즉 블럭이 쌓여야 할 때
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}
		else if (score >= 50000 && score < 75000 && timeDiff > 500)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// 시작 시간 재설정

			// 블럭이 내려갈 수 없을 때, 즉 블럭이 쌓여야 할 때
			if (!isDown)
			{
				StackingBock(bcon, 9);
			}
		}
		else if (score >= 75000 && score < 100000 && timeDiff > 350)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// 시작 시간 재설정

			// 블럭이 내려갈 수 없을 때, 즉 블럭이 쌓여야 할 때
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}
		else if (score >= 100000 && score < 150000 && timeDiff > 200)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// 시작 시간 재설정

			// 블럭이 내려갈 수 없을 때, 즉 블럭이 쌓여야 할 때
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}
		else if (score >= 150000 && timeDiff > 100)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// 시작 시간 재설정

			// 블럭이 내려갈 수 없을 때, 즉 블럭이 쌓여야 할 때
			if (!isDown)
			{
				StackingBock(bcon, 10);
			}
		}

		// 키 입력
		int input = KeyControl();
		// 회전 및 이동 가능 여부 확인
		// 스페이스 키 입력
		if (IsRotate(bcon) && input == KEY_INPUT::SPACE)
		{
			bcon.GetMainBlock()->RotateBlock();
			bcon.GetMainBlock()->DrawBlock();
		}
		// 아래 키 입력
		if (isDown == true && input == KEY_INPUT::DOWN)
		{
			bcon.GetMainBlock()->MoveDown();
			SetClock();	// 시작 시간 재설정

			// 블럭이 내려갈 수 없을 때, 즉 블럭이 쌓여야 할 때
			if (!IsMoveDown(bcon))
			{
				StackingBock(bcon, 9);
			}
		}
		// 왼쪽 키 입력
		if (isLeft == true && input == KEY_INPUT::LEFT)
		{
			bcon.GetMainBlock()->MoveLeft();
		}
		// 오른쪽 키
		if (isRight == true && input == KEY_INPUT::RIGHT)
		{
			bcon.GetMainBlock()->MoveRight();
		}

		// 게임 종료 조건 확인
		if (IsGameOver())
		{
			GameOver();	// 게임 종료 문구 출력
			break;
		}
	}
}