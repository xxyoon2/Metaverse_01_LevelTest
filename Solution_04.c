/*
    [문제를 파악한 내용]
    - 배열의 값을 오름차순 (ex - 1, 2, 3, 4, 5 ...) 순으로 정렬해줘야 함
    - 더 큰 값을 배열의 앞쪽에 둬야 함
    [해결 아이디어]
    - 이중for문을 돌려 배열의 앞(i)과 뒤(j)를 반복적으로 비교
    - 만일 i가 j보다 작을 경우 둘의 값을 swap 시킴 (큰 경우라면 내림차순이 됨)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortArray(int* arr, int n);
void printArray(int* arr, int n);

int main()
{
    int arr[5] = { 5, 2, 4, 1, 3 };
    
    printArray(arr, 5);
    sortArray(arr, 5);
    printArray(arr, 5);
}

void sortArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArray(int* arr, int n)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
