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
