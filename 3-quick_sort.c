#include "sort.h"
/**
 * partition - This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right of pivot
 * @array: subset to sort
 * @low: lowest array position
 * @high: heghest array position
 * @size: Size of original array to sort
 * Return: Pivot (Type:Int)
*/
int partition(int *array, ssize_t low, ssize_t high, ssize_t size)
{
	ssize_t i = 0;
	ssize_t j = 0;
	int tmp;
	int pivot = array[high];

	i = (low - 1);
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quickSorting - The main function that implements QuickSort
 * @arr: subset to sort
 * @low: lowest array position
 * @high: heghest array position
 * @size: Size of original array to sort
 * Return: void
*/
void quickSorting(int *arr, ssize_t low, ssize_t high, ssize_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high, size);
		quickSorting(arr, low, pivot - 1, size);
		quickSorting(arr, pivot + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSorting(array, 0, size - 1, size);
}
