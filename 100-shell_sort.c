#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	/* variable declaration */
	int i, temp;
	size_t gap = 1, j;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		gap /= 3;

		if (gap > 0)
			print_array(array, size);
	}
}
