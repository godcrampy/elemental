#include <stdio.h>
#include "src/array/Array.h"

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int a[n];
	scanArray(a, n);
	shuffleArray(a, n);
	printArray(a, n);
	shuffleArray(a, n);
	printArray(a, n);
	shuffleArray(a, n);
	printArray(a, n);
	shuffleArray(a, n);

	return 0;
}