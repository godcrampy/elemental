#include <stdio.h>
#include "src/array/Array.h"

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int a[n];
	scanArray(a, n);
	reverseArray(a, n);
	printArray(a, n);
	return 0;
}