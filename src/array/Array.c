#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void shuffleArray(int *array, int length)
{
    // random seed
    srand(time(NULL));

    int random;
    for (int i = 0; i < length - 2; i++)
    {
        random = rand() % (length - i) + i;
        swapItems(array, i, random);
    }
}

int sumOfArray(int *array, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += *(array + i);
    }
    return sum;
}

int meanOfArray(int *array, int length)
{
    return sumOfArray(array, length) / length;
}

int minOfArray(int *array, int length)
{
    int min = *array;
    for (int i = 1; i < length; i++)
    {
        if (*(array + i) < min)
        {
            min = *(array + i);
        }
    }
    return min;
}

int maxOfArray(int *array, int length)
{
    int max = *array;
    for (int i = 1; i < length; i++)
    {
        if (*(array + i) > max)
        {
            max = *(array + i);
        }
    }
    return max;
}

int findItem(int *array, int length, int number)
{
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) == number)
        {
            return i;
        }
    }
    return -1;
}

int frequencyOfItem(int *array, int length, int number)
{
    int frequency = 0;
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) == number)
        {
            ++frequency;
        }
        return frequency;
    }
}

void bubbleSort(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (*(array + j) > *(array + j + 1))
            {
                swapItems(array, j, j + 1);
            }
        }
    }
}