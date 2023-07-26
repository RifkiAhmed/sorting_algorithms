#include "sort.h"

/**
 * swap - swap values of two elements in @array
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
 * Hoare_partition - algorithm (using Hoare partition scheme) that reorders
 * the @array; all elements with values less than the pivot come before it,
 * while elements with values greater than or equal to the pivot come after it.
 * After this partitioning.
 * @array: pointer to the array to reorder
 * @size: size of the @array
 * @left: index of the element at the top left of the @array
 * @right: index of the element at the top right of the @array (pivot)
 *
 * Return: index of the pivot after swap
 */

int Hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i, j;

	i = left;
	j = right;

	do {
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		swap(array, size, &array[i], &array[j]);
	} while (1);
}

/**
 * Quicksort - algorithm (using Hoare partition scheme) that sorts an array
 * of integers in ascending order using the Quick sort algorithm
 * @array: pointer to the array to reorder
 * @size: size of the @array
 * @left: index of the element at the top left of the @array
 * @right: index of the element at the top right of the @array (it's pivot)
 */

void Quicksort(int *array, size_t size, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = Hoare_partition(array, size, left, right);
		Quicksort(array, size, left, pivot - 1);
		Quicksort(array, size, pivot + 1, right);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm. Quicksort is a divide-and-conquer algorithm
 * @array: pointer to the array to sort
 * @size: size of @array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array && size >= 2)
		Quicksort(array, size, 0, size - 1);
}
