#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int max = array[0];
	int min = array[0];
	size_t counting_size;
	int *counting_array;

	if (array == NULL || size <= 1)
		return;

	/* Find the maximum and minimum values in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}

	/* Create a counting array of size max + 1 and initialize it to 0 */
	counting_size = max - min + 1;
	counting_array = (int *)malloc(counting_size * sizeof(int));

	if (counting_array == NULL)
		return;

	for (i = 0; i < counting_size; i++)
		counting_array[i] = 0;

	/* Count the occurrences of each element in the original array */
	for (i = 0; i < size; i++)
		counting_array[array[i] - min]++;

	/* Print the counting array as requested */
	for (i = 0; i < counting_size; i++)
	{
		printf("%d", counting_array[i]);
		if (i < counting_size - 1)
			printf(", ");
	}
	printf("\n");

	/* Copy the sorted values back to the original array */
	j = 0;
	for (i = 0; i < counting_size; i++)
	{
		while (counting_array[i] > 0)
		{
			array[j] = i + min;
			j++;
			counting_array[i]--;
		}
	}

	/* Free dynamically allocated memory */
	free(counting_array);
}
