#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int i, j, max = 0;
	int *count, *output;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (j = 0, i = 0; i < (int)size; i++, j++)
		array[j] = output[i];

	for (i = 0; i <= max; i++)
		printf("%d, ", count[i]);
	printf("\n");

	free(count);
	free(output);
}
