#include <stdio.h>
#include <stdlib.h>
#include  "array.h"

int main(int argc, char const *argv[])
{
	int base[10] = {444, 555, 666, 333, 222, 111, 888, 999, 101, 1001};
	int arr[10] = {444, 555, 666, 333, 222, 111, 888, 999, 101, 1001};
	int x = 10;
	int y[x];

	arrayPrint(arr, 10);

	printf("bubble\n");
	arrayBubbleSort(arr, 10);
	arrayPrint(arr, 10);
	arrayCopy(base, arr, 10);

	printf("bubble1\n");
	arrayBubbleSort1(arr, 10);
	arrayPrint(arr, 10);
	arrayCopy(base, arr, 10);

	printf("ins\n");
	arrayInsertSort(arr, 10);
	arrayPrint(arr, 10);
	arrayCopy(base, arr, 10);

	printf("ins1\n");
	arrayInsertSort1(arr, 10);
	arrayPrint(arr, 10);
	arrayCopy(base, arr, 10);

	printf("select\n");
	arrayPrint(arr, 10);
	arraySelectSort(arr, 10);
	arrayPrint(arr, 10);
	arrayCopy(base, arr, 10);

	printf("is sorted %d\n", arrayIsSorted(arr, 10));
	arraySelectSort(arr, 10);
	printf("is sorted %d\n", arrayIsSorted(arr, 10));

	printf("searched at %d\n", arraySearch(arr, 10, 555));
	printf("binary searched at %d\n", arrayBinarySearch(arr, 10, 555));

	arrayCopy(base, y, 10);
	arrayPrint(y, 10);
	quickSort(y, 0, 10);
	arrayPrint(y, 10);

	arrayPrintMaxSubArray(arr, 10, 66);
	return 0;
}