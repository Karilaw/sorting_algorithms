#include "sort.h"

/**
 * counting_sort - sorts an array of integers in
 * ascending order using theCounting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max, i, j;
	int *count, *output;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = output[j];

	free(count);
	free(output);
}
