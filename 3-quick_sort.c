#include "sort.h"

/**
 * lomuto_partition - partitions an array
 * using the Lomuto partition scheme
 * @array: the array to be partitioned
 * @low: the lowest index of the partition
 * @high: the highest index of the partition
 * @size: the size of the array
 *
 * Return: the final index of the pivot
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, temp, i, j;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_rec - sorts an array of integers in
 * ascending order
 * using the Quick sort algorithm (recursive function)
 * @array: the array to be sorted
 * @low: the lowest index of the partition to be sorted
 * @high: the highest index of the partition to be sorted
 * @size: the size of the array
 */

void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers
 * in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
