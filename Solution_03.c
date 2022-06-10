#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num = 5;
    scanf("%d", &num);


    for (int i = 1; i <= (num - 1) * 2 + 1; i += 2)
    {
        for (int j = num - (i / 2 + 1); j > 0; --j)
        {
            printf(" ");
        }

        for (int j = i; j > 0; --j)
        {
            printf("*");
        }
        
        printf("\n");
    }
}
