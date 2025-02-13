#include "sort.h"
#define MAX_SIZE 2048

void merge(int *array, int *left, size_t l_size, int *right, size_t r_size);

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int left[MAX_SIZE], right[MAX_SIZE];
	size_t i, middle;

	if (!array || size < 2)
	{
		return;
	}

	middle = size / 2;

	for (i = 0; i < middle; i++)
	{
		left[i] = array[i];
	}

	for (i = middle; i < size; i++)
	{
		right[i - middle] = array[i];
	}

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merge(array, left, middle, right, size - middle);
}

/**
 * merge - Merges two subarrays into a single sorted array.
 *
 * @array: The array to be sorted.
 * @left: The left subarray.
 * @l_size: The size of the left subarray.
 * @right: The right subarray.
 * @r_size: The size of the right subarray.
 */
void merge(int *array, int *left, size_t l_size, int *right, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l_size);
	printf("[right]: ");
	print_array(right, r_size);

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < l_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < r_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_array(array, l_size + r_size);
}
