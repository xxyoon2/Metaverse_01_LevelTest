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
}
