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
