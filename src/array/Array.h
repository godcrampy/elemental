#ifndef ARRAY_H
#define ARRAY_H

// scan array from the user O(length)
void scanArray(int *array, int length);

// print array on the command line O(length)
void printArray(int *array, int length);

// rotate array to the left in steps O(length*steps)
void rotateArray(int *array, int length, int steps);

// rotate array to the left by one step O(length)
void rotateArrayOnce(int *array, int length);

// reverse array O(length/2)
void reverseArray(int *array, int length);

// swap items of array O(1)
void swapItems(int *array, int left, int right);

// shuffle items in array O(length)
void shuffleArray(int *array, int length);

// sum of array O(length)
int sumOfArray(int *array, int length);

// mean of array O(length)
int meanOfArray(int *array, int length);

// max and min of array O(length)
int minOfArray(int *array, int length);
int maxOfArray(int *array, int length);

// find first occurence of a member O(length)
int findItem(int *array, int length, int number);

// frequency of an item O(length)
int frequencyOfItem(int *array, int length, int number);

// bubble sort array O(length^2)
void bubbleSort(int *array, int length);

// selection sort array O(length^2)
void selectionSort(int *array, int length);

// insertion sort
void insertionSort(int * array, int length);


#endif