#include <stdio.h>
#include "Array.h"

void scanArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        scanf("%d", array + i);
        getchar();
    }
}

void printArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

void rotateArrayOnce(int *array, int length)
{
    int temp = *(array);
    for (int i = 0; i < length - 1; i++)
    {
        *(array + i) = *(array + i + 1);
    }
    *(array + length - 1) = temp;
}

void rotateArray(int *array, int length, int steps)
{
    for (int i = 0; i < steps; i++)
    {
        rotateArrayOnce(array, length);
    }
}

void reverseArray(int *array, int length)
{
    //1, 2, 3, 4 or 1, 2, 3, 4, 5
    for (int i = 0; i < length / 2; i++)
    {
        // Position to be swapped with
        int r = length - i - 1;
        swapItems(array, i, r);
    }
}

void swapItems(int *array, int left, int right)
{
    int temp = *(array + left);
    *(array + left) = *(array + right);
    *(array + right) = temp;
}