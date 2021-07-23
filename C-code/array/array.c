#include <stdio.h>
#include <stdlib.h>
#include  "array.h"

int arrayBubbleSort(int *arr, int size)
{
	int i, j, tmp;
	if (size < 1)
	{
		return 0;
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return 1;
}
int arrayBubbleSort1(int *arr, int size)
{
	int i, j, tmp, swapped = 0;
	if (size < 1)
	{
		return 0;
	}
	do
	{
		swapped = 0;
		for (int i = 0; i < size-1; ++i)
		{
			if (arr[i] > arr[i+1])
			{
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				swapped = 1;
			}
		}
	} while (swapped == 1);
	return 1;
}
int arrayInsertSort(int *arr, int size)
{
	int i, j, tmp;
	if (size < 1)
	{
		return 0;
	}
	for (int i = 1; i < size; ++i)
	{
		j = i;
		while(j > 0) {
			if (arr[j -1] > arr[j])
			{
				tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			} else {
				break;
			}
			j--;
		}
	}
	return 1;
}
int arrayInsertSort1(int *arr, int size)
{
	int i, j, tmp;
	if (size < 1)
	{
		return 0;
	}
	for (i = 0; i < size; ++i)
	{
		tmp = arr[i];
		j = i -1;
		while(j >= 0 && arr[j] > tmp){
			arr[j+1] = arr[j];
			j = j -1;
		}
		arr[j+1] = tmp;
	}
	return 1;
}

int arraySelectSort(int *arr, int size)
{
	int i, j, min, tmp;
	if (size < 1)
	{
		return 0;
	}
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i+1; j < size; j++)
		{
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if (min != i)
		{
			tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}
	}
	return 1;
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int tmp;
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
                              //swap(&arr[i], &arr[j]);
        }
    }
    tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
                              //swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int arrayRadixSort(int *arr, int size)
{

}

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
  
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
              
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
                                            //swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
                                                //swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int arraySearch(int *arr, int size, int data)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == data)
		{
			return i;
		}
	}
	return -1;
}
int arrayBinarySearch(int *arr, int size, int data)
{
	int i, j , mid;
	i = 0;
	j = size;
	while(i < j) {
		mid = (i + j)/2;
		if (arr[mid] == data)
		{
			return mid;
		} else if (data < arr[mid]) {
				j = mid-1;
		} else {
			i = mid+1;
		}
	}
	return -1;
}

int arrayIsSorted(int *arr, int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (arr[i-1] > arr[i])
		{
			return 0;
		}
	}
	return 1;
}

int arrayFindDup(int *arr, int size)
{

}

int arrayCopy(int *src, int *dst, int size)
{
	for (int i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
	return 0;
}

int arrayPrint(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}

int arrayPrintMaxSubArray(int *arr, int size, int num)
{
	int len = 0, endindex = 0, sum = 0;
	int i , j;
	for ( i = 0; i < size; i++)
	{
		sum = 0;
		for ( j = i+1; j < size; j++)
		{
			sum += arr[j];
			if (sum == num) {
				if (len < (j - i )) {
					len = j - i;
					endindex = j;
					printf("endindex %d  %d (%d)found\n", i, j, len);
				}
			}
			if (sum > num)
				break;
		}
	}
	if(len)
		printf("Max len : %d   [ %d ---- %d ]\n", len, endindex-len+1, endindex);
	else
		printf("Num %d not found\n", num);

	return 1;
}