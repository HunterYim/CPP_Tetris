/*
	���� �̸�: TetrisMain.cpp
	���� ����
		- ��Ʈ���� ���� ���� �Լ� ����
*/

#include "TetrisCommonDelc.h"
#include "GameFunc.h"
#include "Block.h"
#include "TetrisMenu.h"
#include "BlockController.h"
#include "TetrisController.h"

int main(void)
{
	SettingConsole();	// �ܼ�â ����

	while (1)
	{
		TetrisMenu menu;			// �޴� ���� Ŭ���� ��ü ����
		TetrisController tcon;		// ���� ���� ��Ʈ�ѷ� Ŭ���� ��ü ����
		menu.GameInit();			// ���� �޴� â ����
		switch (menu.SelectMenu())	// ���� �޴� ����
		{
		case 0:	// ���� ����
		{
			// TetrisController Ŭ������ GameMain �޼ҵ带 �����Ͽ� ������ ���� ���� ����
			tcon.GameMain();
			break;
		}
		case 1:	// ���� ����
		{
			menu.TetrisInfo();
			break;
		}
		case 2:	// ����
		{
			exit(1);
			break;
		}
		}
	}
	return 0;
}