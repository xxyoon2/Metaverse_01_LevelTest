/*
    [문제를 파악한 내용]
    - 1 ~ 최대값 사이의 랜덤값을 입력받은 만큼 생성(출력)해야 함
    - 겹치는 랜덤값이 있어서는 안됨
    [해결 아이디어]
    - 배열을 생성해 배열에 랜덤값을 저장
    - 범위 내의 랜덤값을 받아온 후, 만약 배열에 동일한 랜덤값이 없다면 저장
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void RottoNum(int max, int num);
void InputNum(int* max, int* num);

int main()
{
    int maxNum, numNum;
    
    InputNum(&maxNum, &numNum);
    RottoNum(maxNum, numNum);
}

void InputNum(int* max, int* num)
{
    printf("최대값 : ");
    scanf("%d", max);
    printf("생성숫자 : ");
    scanf("%d", num);
}

void RottoNum(int max, int num)
{
    srand(time(NULL));

    int* randArray = (int*)malloc(sizeof(int) * num);
    int numCount = 0;
    while (numCount < num)
    {
        int randNum = rand() % max + 1;
        
        bool isNumExistence = false;
        for (int i = 0; i < numCount; i++)
        {
            if (randNum == randArray[i])
            {
                isNumExistence = true;
                break;
            }
        }

        if (!isNumExistence)
        {
            randArray[numCount] = randNum;
            printf("%d\n", randArray[numCount]);
            numCount++;
        }
    }

    free(randArray);
}
