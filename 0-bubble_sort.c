#include "sort.h"
/**
 * bubble_sort - sort elements min - max
 * @array: array of elements
 * @size: size of array
*/

void bubble_sort(int *array, size_t size)
{
    size_t i = 0;
    size_t index;
    size_t tmp = 0;

    if (size < 2)
    {
        return;
    }

    while (i < size)
    {
        for (index = 0; index < size; index++)
        {
            if (array[index] > array[index + 1] && array[index + 1])
            {
                tmp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = tmp;
                print_array(array, size);
            }
        }
        i++;
    }
}