/*
	파일 이름: TetrisCommonDelc.h
	파일 설명
		- 공통 헤더 선언
		- 상수 선언
		- namespace 선언
		- 게임 공통 함수 정의
*/

#pragma once
#ifndef __TETRIS_COMMON_H__
#define __TETRIS_COMMON_H__

#define _CRT_SECURE_NO_WARNINGS

// 상수 선언
#define BLOCK_SIZE 4
#define MAP_WIDTH 12
#define MAP_HEIGHT 26

// 공통 헤더 파일 선언
#include <iostream>
#include <cstring>
#include <cstdio>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <random>
using namespace std;

// 키보드 입력 값
namespace KEY_INPUT
{
	enum
	{
		DOWN = 1,
		LEFT = 2,
		RIGHT = 3,
		SPACE = 4,
		UP = 5
	};
}

// 테트리스 블럭 목록
namespace BLOCK
{
	enum
	{
		I = 0,
		J = 1,
		L = 2,
		O = 3,
		S = 4,
		T = 5,
		Z = 6
	};
}

// 블럭 타입 목록
namespace BLOCK_TYPE
{
	enum
	{
		MAIN = 0,
		NEXT = 1
	};
}

#endif // !__TETRIS_COMMON_H__