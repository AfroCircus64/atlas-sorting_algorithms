#include "sort.h"
#include <sys/types.h>
/**
* swap - swap the positions of two elements
* @array: array
* @item1: element
* @item2: element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * lomuto_sort - lomuto partition sorting scheme implementation
 * @array: array
 * @first: first element
 * @last: last element
 * @size: size of array
 * Return: return the position of the last element sorted
 */
int lomuto_sort(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *quik_sort - qucksort algorithm
 *@array: array
 *@first: first element
 *@last: last element
 *@size: size of array
 */
void quik_sort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_sort(array, first, last, size);

		quik_sort(array, first, position - 1, size);
		quik_sort(array, position + 1, last, size);
	}
}
/**
 *quick_sort - quicksort algorithm terrain
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quik_sort(array, 0, size - 1, size);
}
