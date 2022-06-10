/*
    [문제를 파악한 내용]
    - n*n 배열에서 n을 입력받음
    - 달팽이관모양으로 숫자를 1 ~ n*n까지 순차적으로 출력해줌
    [해결 아이디어]
    - 2차원 배열에 조건에 따라 숫자를 순차적으로 저장하려고 했는데
    동적 할당을 이용해 그때그때 메모리 조정해주려고 욕심냈다가 다 못끝내버렸습니다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num;

    printf("배열의 크기를 입력하시오.\n : ");
    scanf("%d", &num);

    int** arr = (int**)malloc(sizeof(int*) * num);

    for (int i = 1; i <= num; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * num);
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {

            arr[i][j] = 0;
            printf("%d\t", arr[i][j]);
        }
        printf("\n\n");
    }

    /*for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            arr[i][j] = countNum;
            printf("%d\t", arr[i][j]);

            countNum++;
        }
        printf("\n\n");
    }*/

    int count = 1;
    int countNum = num*num;
    int i = 1, j = 1, a = 1;
    while (count <= countNum)
    {
        /*
        for (int i = 0; arr[i][0] != '\0'; i++)
        {
            arr[i][0] = count;
            //printf("%d  ", arr[i][0]);
            ++count;
        }
        */

        switch (a)
        {
        case 1:
            arr[i][j++] = count;
            if (arr[i][j] != 0)
            {
                --j;
                ++i;
                ++a;
            }
            break;
        case 2:
            arr[i++][j] = count;
            if (arr[i][j] != 0)
            {
                --i;
                --j;
                ++a;
            }
            break;
        case 3:
            arr[i][j--] = count;
            if (arr[i][j] != 0)
            {
                --i;
                ++j;
                ++a;
            }
            break;
        case 4:
            arr[i--][j] = count;
            if (arr[i][j] != 0)
            {
                ++j;
                ++i;
                a = 1;
            }
        }

        count++;
    }

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n\n");
    }
}
