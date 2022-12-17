#include <stdio.h>

void swap(int *xn, int *yn)
{
	int temp = *xn;
	*xn = *yn;
	*yn = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_ind;

	for (i = 0; i < n-1; i++)
	{
        //find smallest element
		min_ind = i; 
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_ind])
			min_ind = j;
        // swap found element
		if(min_ind != i)
			swap(&arr[min_ind], &arr[i]);
	}
}


void print_arr(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	printf("Sorted array: \n");
	print_arr(arr, n);
	return 0;
}
