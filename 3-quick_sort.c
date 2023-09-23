#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 *
 * @array: The array to be partitioned
 * @size: Number of elements in the array
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quicksort - Recursive function to perform quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 */
void quicksort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_idx = lomuto_partition(array, size, low, high);

		quicksort(array, size, low, pivot_idx - 1);
		quicksort(array, size, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
