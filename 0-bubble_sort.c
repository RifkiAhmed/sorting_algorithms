#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm that repeatedly steps through @array
 * element by element, comparing the current element with the one
 * after it, swapping their values if needed. These passes through
 * the @array are repeated until no swaps had to be performed during a pass,
 * meaning that the @array has become fully sorted
 *
 * @array: pointer to an integers array to sort
 * @size: size of the @array
 *
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i = 0, j, swap;

	if (array == NULL || size < 2)
		return;
	for ( ; i < size; i++)
	{
		swap = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swap++;
				print_array(array, size);
			}
		}
		if (!swap)
			return;
	}
}
