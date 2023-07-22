#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm. The algorithm divides the
 * input array into two parts: a sorted sublist of items which is
 * built up from left to right and a sublist of the remaining
 * unsorted items that occupy the rest of the array. Initially,
 * the sorted sublist is empty and the unsorted sublist is the
 * entire input array. The algorithm proceeds by finding the smallest
 * element in the unsorted sublist, swapping it with the leftmost
 * unsorted element (putting it in sorted order), and moving
 * the sublist boundaries one element to the right.
 *
 * @array: pointer to an integers array to sort
 * @size: size of the @array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, index;
	int tmp;

	if (size < 2)
		return;
	for ( ; i < size - 1; i++)
	{
		index = 0;
		tmp = array[i];
		for (j = i; j < size; j++)
		{
			if (tmp > array[j])
			{
				tmp = array[j];
				index = j;
			}
		}
		if (index)
		{
			array[index] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
