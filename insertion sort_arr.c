#include <math.h>
#include <stdio.h>

void insort(int arr[], int n)
{
	int i, poi, j;
	for (i = 1; i < n; i++) {
		poi = arr[i];
		j = i - 1;

		// we move the elements of array greater than poi to one position ahead
		while (j >= 0 && arr[j] > poi) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = poi;
	}
}

void prnArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {12 , 13 , 15 , 10 , 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	insort(arr, n);
	prnArr(arr, n);

	return 0;
}
