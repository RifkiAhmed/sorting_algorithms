#include "sort.h"

/**
 * partition - algorithm (using Lomuto partition scheme) that reorders
 * the @array; all elements with values less than the pivot (last element
 * in the sub-lists of the @array) come before it, while all elements with
 * values greater than or equal to the pivot come after it.
 * After this partitioning, the pivot is in its final position
 *
 * @array: pointer to the array to reorder
 * @size: size of the @array
 * @top_left: index of the element at the top left of the @array
 * @top_right: index of the element at the top right of the @array (it's pivot)
 *
 * Return: index of the pivot after swap
 */
int partition(int *array, size_t size, size_t top_left, size_t top_right)
{
	int *pivot = &array[top_right - 1];
	int current;
	size_t i;

	for (i = top_left; i < top_right; i++)
	{
		if (array[i] < *pivot)
		{
			if (i != top_left)
			{
				/** swap */
				current = array[i];
				array[i] = array[top_left];
				array = current;
				print_array(array, size);
			}
			top_left += 1;
		}
	}
	if (top_left != top_right - 1)
	{
		/** swap */
		current = *pivot;
		*pivot = array[top_left];
		array[top_left] = current;
		print_array(array, size);
	}
	return (top_left);
}

/**
 * Lumoto - algorithm (using Lomuto partition scheme) that sorts recursively
 * the sub-list of lesser elements and the sub-list of greater elements in
 * the @array
 *
 * @array: pointer to the array to reorder
 * @size: size of the @array
 * @top_left: index of the element at the top left of the @array
 * @top_right: index of the element at the top right of the @array (it's pivot)
 */
void Lumoto(int *array, size_t size, size_t top_left, size_t top_right)
{
	size_t pivot;

	if (top_left < top_right)
	{
		pivot = partition(array, size, top_left, top_right);
		Lumoto(array, size,  top_left, pivot);
		Lumoto(array, size, pivot + 1, top_right);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm. Quicksort is a divide-and-conquer algorithm
 *
 * @array: pointer to the array to sort
 * @size: size of @array
 */
void quick_sort(int *array, size_t size)
{
	size_t n = size;

	Lumoto(array, size, 0, n);
}
