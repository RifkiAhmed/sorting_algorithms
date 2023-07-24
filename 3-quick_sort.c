#include "sort.h"

/**
 * swap - swap values of two elements in @array
 *
 * @array: pointer to array of integers
 * @size: size of the @array
 * @a: pointer to 1st element
 * @b: pointer to 2d element
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int c;

	if (*a != *b)
	{
		c = *a;
		*a = *b;
		*b = c;

		print_array(array, size);
	}
}

/**
 * Lumoto_partition - algorithm (using Lomuto partition scheme) that reorders
 * the @array; all elements with values less than the pivot come before it,
 * while elements with values greater than or equal to the pivot come after it.
 * After this partitioning, the pivot is in its final position
 *
 * @array: pointer to the array to reorder
 * @size: size of the @array
 * @left: index of the element at the top left of the @array
 * @right: index of the element at the top right of the @array (pivot)
 *
 * Return: index of the pivot after swap
 */
int Lumoto_partition(int *array, size_t size, int left, int right)
{
	int *pivot = &array[right];
	int j;

	for (j = left; j < right; j++)
		if (array[j] < *pivot)
		{
			swap(array, size, &array[j], &array[left]);
			left++;
		}
	swap(array, size, &array[left], pivot);
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
void Lumoto(int *array, size_t size, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = Lumoto_partition(array, size, left, right);
		Lumoto(array, size,  left, pivot - 1);
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
		Lumoto(array, size, 0, size - 1);
}
