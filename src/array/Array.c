#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
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

void copyArray(int *originalArray, int originalStart, int *finalArray, int finalStart, int length)
{
    for (int i = 0; i < length; i++)
    {
        *(finalArray + finalStart + i) = *(originalArray + originalStart + i);
    }
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

void selectionSort(int *array, int length)
{
    int min;
    for (int i = 0; i < length; i++)
    {
        //i determines the first element of unsorted list
        //min locates the minimum number
        min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (*(array + j) < *(array + min))
            {
                min = j;
            }
        }
        swapItems(array, min, i);
    }
}

void insertionSort(int *array, int length)
{
    int min;
    // i is the location of the first member of unsorted list
    for (int i = 1; i < length; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            //j is the iterator that goes up the list
            if (*(array + j) > *(array + j + 1))
            {
                swapItems(array, j, j + 1);
            }
            else
            {
                break;
            }
        }
    }
}

void mergeSort(int *array, int length)
{
    int temp[length];
    splitArray(temp, array, 0, length - 1);
}

void splitArray(int *temp, int *array, int leftStart, int rightEnd)
{
    // 1 2 3 4 5
    if (leftStart >= rightEnd)
    {
        return;
    }
    int middle = (leftStart + rightEnd) / 2;
    splitArray(temp, array, leftStart, middle);
    splitArray(temp, array, middle + 1, rightEnd);
    mergeHalves(temp, array, leftStart, rightEnd);
}

void mergeHalves(int *temp, int *array, int leftStart, int rightEnd)
{
    int tempPointer = leftStart;
    int leftEnd = (leftStart + rightEnd) / 2;
    int rightStart = leftEnd + 1;
    int leftPointer = leftStart;
    int rightPointer = rightStart;
    while (leftPointer <= leftEnd && rightPointer <= rightEnd)
    {
        if (*(array + leftPointer) <= *(array + rightPointer))
        {
            *(temp + tempPointer) = *(array + leftPointer);
            leftPointer++;
        }
        else
        {
            *(temp + tempPointer) = *(array + rightPointer);
            rightPointer++;
        }
        tempPointer++;
    }
    copyArray(array, leftPointer, temp, tempPointer, leftEnd - leftPointer + 1);
    copyArray(array, rightPointer, temp, tempPointer, rightEnd - rightPointer + 1);
    copyArray(temp, leftStart, array, leftStart, rightEnd - leftStart + 1);
}

void quickSort(int *array, int length)
{
    managePartitioning(array, 0, length - 1);
}

void managePartitioning(int *array, int left, int right)
{
    if (left < right)
    {
        int pivot = doPartition(array, left, right);
        managePartitioning(array, left, pivot - 1);
        managePartitioning(array, pivot + 1, right);
    }
}

int doPartition(int *array, int first, int last)
{
    //last is the index of last element
    int leftPointer = first + 1, rightPointer = last, pivot = *(array + first);
    if (leftPointer < rightPointer)
    {
        while (leftPointer < rightPointer)
        {
            while (*(array + leftPointer) <= pivot)
            {
                leftPointer++;
            }
            while (*(array + rightPointer) > pivot)
            {
                rightPointer--;
            }
            if (leftPointer < rightPointer)
            {
                swapItems(array, leftPointer, rightPointer);
            }
        }
        swapItems(array, first, rightPointer);
    }
    else if (leftPointer == rightPointer)
    {
        if (*(array + leftPointer - 1) > *(array + rightPointer))
        {
            swapItems(array, leftPointer - 1, rightPointer);
        }
    }
    return rightPointer;
}

int isSorted(int *array, int length)
{
    for (int i = 1; i < length; i++)
    {
        if (*(array + i) < *(array + i - 1))
        {
            return 0;
        }
    }
    return 1;
}
