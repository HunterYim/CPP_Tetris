/*
	파일 이름: TetrisMain.cpp
	파일 설명
		- 테트리스 게임 메인 함수 파일
*/

#include "TetrisCommonDelc.h"
#include "GameFunc.h"
#include "Block.h"
#include "TetrisMenu.h"
#include "BlockController.h"
#include "TetrisController.h"

int main(void)
{
	SettingConsole();	// 콘솔창 세팅

	while (1)
	{
		TetrisMenu menu;			// 메뉴 설정 클래스 객체 생성
		TetrisController tcon;		// 메인 게임 컨트롤러 클래스 객체 생성
		menu.GameInit();			// 게임 메뉴 창 생성
		switch (menu.SelectMenu())	// 게임 메뉴 선택
		{
		case 0:	// 게임 시작
		{
			// TetrisController 클래스의 GameMain 메소드를 실행하여 게임의 메인 루프 실행
			tcon.GameMain();
			break;
		}
		case 1:	// 게임 정보
		{
			menu.TetrisInfo();
			break;
		}
		case 2:	// 종료
		{
			exit(1);
			break;
		}
		}
	}
	return 0;
}