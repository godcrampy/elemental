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

// copy an array to another array O(length)
void copyArray(int *originalArray, int originalStart, int *finalArray, int finalStart, int length);

// bubble sort array O(length^2)
void bubbleSort(int *array, int length);

// selection sort array O(length^2)
void selectionSort(int *array, int length);

// insertion sort array O(length^2)
void insertionSort(int *array, int length);

// merge sort array O(length*log(length))
void mergeSort(int *array, int length);
// Helper functions
void splitArray(int *temp, int *array, int leftStart, int rightEnd);
void mergeHalves(int *temp, int *array, int leftStart, int rightEnd);

// quick sort array O(length*log(length))
void quickSort(int *array, int length);
void managePartitioning(int *array, int left, int right);
int doPartition(int *array, int first, int last);

// is array sorted O(length)
int isSorted(int *array, int length);

#endif