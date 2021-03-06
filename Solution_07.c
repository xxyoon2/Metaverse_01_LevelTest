/*
	[문제를 파악한 내용]
	- 1 ~ 25 까지 랜덤으로 배치된 5*5 빙고판 생성
	- 숫자를 입력받으면 그에 대한 숫자가 지워지고, 빙고줄이 완성될 때마다 빙고줄 개수 추가
	[해결 아이디어]
	- 빙고판 생성하는 함수 / 빙고 판정하는 함수 / 빙고판 출력하는 함수 / 플레이하는 함수
	- 1) 생성하는 함수는 초기에 빙고판 생성해주는 함수
	- 2) 빙고 판정하는 함수 - 가로 판정 / 세로 판정 / 대각선 판정 확인해 빙고줄 반환
	- 3) 빙고판 콘솔창에 출력
	- 4) 함수들을 이용해 플레이
	- 따로 게임 종료하는 조건이 없길래 빙고줄 다 채워야만 멈추도록 설계했습니다 ^^
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void Create_Map(int(*arr)[5], int width_n, int height_n);	// 맵 생성
int Judgment(int(*arr)[5], int width_n, int height_n);
void Print_Map(int(*arr)[5], int width_n, int height_n);	//한 턴 지날때 맵 갱신해줌
void Play_Game();	//게임플레이

int main()
{
	Play_Game();
}

void Create_Map(int(*arr)[5], int width_n, int height_n)
{
	srand(time(NULL));
	int count = 0;
	int randArr[25] = { 0 };

	while (count < 25)
	{
		int randNum = rand() % 25 + 1;
		bool isRandNumExistence = false;
		for (int i = 0; i <= count; i++)
		{
			if (randNum == randArr[i])
			{
				isRandNumExistence = true;
				break;
			}
		}

		if (!isRandNumExistence)
		{
			randArr[count++] = randNum;
		}

	}

	for (int i = 0; i < height_n; i++)
	{
		for (int j = 0; j < width_n; j++)
		{
			arr[i][j] = randArr[--count];
		}
	}

}

void Print_Map(int(*arr)[5], int width_n, int height_n)
{
	for (int i = 0; i < width_n; i++)
	{
		for (int j = 0; j < height_n; j++)
		{
			if (arr[i][j] == 0)
				printf("	");
			else
				printf("%d	", arr[i][j]);
		}
		printf("\n\n");
	}
}

int Judgment(int(*arr)[5], int arrNum1, int arrNum2)
{
	int count_bingo = 0;

	bool diagonal_judgment1 = true;	// 대각선1 판정
	bool diagonal_judgment2 = true;	// 대각선2 판정
	for (int i = 0; i < arrNum1; i++)
	{
		bool horizontal_judgment = true;	// 가로 판정
		bool vertical_judgment = true;		// 세로 판정

		for (int j = 0; j < arrNum2; j++)
		{
			if (arr[i][j] != 0)
				horizontal_judgment = false;
			if (arr[j][i] != 0)
				vertical_judgment = false;

			if (i == j && arr[i][j] != 0)
				diagonal_judgment1 = false;
			if (i + j == 4 && arr[i][j] != 0)
				diagonal_judgment2 = false;
		}

		if (horizontal_judgment)
			count_bingo++;
		if (vertical_judgment)
			count_bingo++;
	}

	if (diagonal_judgment1)
		count_bingo++;
	if (diagonal_judgment2)
		count_bingo++;

	return count_bingo;
}

void Play_Game()
{
	int Bingo[5][5] = { 0 };
	Create_Map(Bingo, 5, 5);

	int bingo = 0;
	while (bingo < 12)
	{
		Print_Map(Bingo, 5, 5);
		
		int num;

		printf("현재 %d줄의 빙고가 완성되었습니다.\n", bingo);
		printf("숫자를 입력해주세요 : ");
		scanf("%d", &num);

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (num == Bingo[i][j])
				{
					Bingo[i][j] = 0;
				}
			}
		}
		
		bingo = Judgment(Bingo, 5, 5);
		
		system("cls");
	}

	printf("%d줄의 빙고를 모두 완성하셨습니다.", bingo);

}

