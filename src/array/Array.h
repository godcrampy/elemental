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

// reverse array
void reverseArray(int *array, int length);

// swap items of array
void swapItems(int *array, int left, int right);

// shuffle items in array
void shuffleArray(int *array, int length);

// sum of array
int sumOfArray(int *array, int length);

// mean of array
int meanOfArray(int *array, int length);

#endif