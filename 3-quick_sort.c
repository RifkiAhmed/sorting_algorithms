#include "sort.h"

/**
 * Lumoto_partition - algorithm (using Lomuto partition scheme) that reorders
 * the @array; all elements with values less than the pivot come before it,
 * while elements with values greater than or equal to the pivot come after it.
 * After this partitioning, the pivot is in its final position
 *
 * @array: pointer to the array to reorder
 * @size: size of the @array
 * @left: index of the element at the top left of the @array
 * @right: index of the element at the top right of the @array (it's pivot)
 *
 * Return: index of the pivot after swap
 */
int Lumoto_partition(int *array, size_t size, size_t left, size_t right)
{
	int *pivot = &array[right - 1];
	int current;
	size_t i;

	for (i = left; i < right; i++)
	{
		if (array[i] < *pivot)
		{
			if (array[i] != array[left])
			{
				/** swap */
				current = array[i];
				array[i] = array[left];
				array[left] = current;
				print_array(array, size);
			}
			left += 1;
		}
	}
	if (left != right - 1)
	{
		/** swap */
		current = *pivot;
		*pivot = array[left];
		array[left] = current;
		print_array(array, size);
	}
	return (left);
}

/**
 * Lumoto - algorithm (using Lomuto partition scheme) that sorts recursively
 * the sub-list of lesser elements and the sub-list of greater elements in
 * the @array
 *
 * @array: pointer to the array to reorder
 * @size: size of the @array
 * @left: index of the element at the top left of the @array
 * @right: index of the element at the top right of the @array (it's pivot)
 */
void Lumoto(int *array, size_t size, size_t left, size_t right)
{
	size_t pivot;

	if (left < right)
	{
		pivot = Lumoto_partition(array, size, left, right);
		Lumoto(array, size,  left, pivot);
		Lumoto(array, size, pivot + 1, right);
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
	if (array != NULL && size >= 2)
		Lumoto(array, size, 0, size);
}
