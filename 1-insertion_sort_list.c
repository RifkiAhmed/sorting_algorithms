#include "sort.h"

/**
 * swap_nodes - swaps two nodes in doubly linked list @list
 *
 * @list: pointer to the pointer to doubly linked list
 * @ptr1: pointer to 1st node
 * @ptr2: pointer to 2d node
 */
void swap_nodes(listint_t **list, listint_t *ptr1, listint_t *ptr2)
{
	/** ptr1->n > ptr2->n */

	/** check if ptr1 is not the last element in @list*/
	if (ptr1->prev)
		ptr1->prev->next = ptr2;
	/** check if ptr2 is not the first element in @list */
	if (ptr2->next)
		ptr2->next->prev = ptr1;
	ptr1->next = ptr2->next;
	ptr2->prev = ptr1->prev;
	ptr1->prev = ptr2;
	ptr2->next = ptr1;
	if (!ptr2->prev)
		*list = ptr2;
	print_list(*list);
}

/**
 * insertion_sort_list -  sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm; At each array-position, it checks
 * the value there against the largest value in the sorted list (which happens
 * to be next to it, in the previous position checked). If larger, it
 * leaves the element in place and moves to the next. If smaller, it finds the
 * correct position within the sorted list, shifts all the larger values up to
 * make a space, and inserts into that correct position.
 *
 * @list: pointer to the pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (!list || !(*list)->next)
		return;

	current = *list;
	while (current->next)
	{
		next = current->next;
		if (current->n > next->n)
		{
			swap_nodes(list, current, next);
			while (next->prev)
			{
				if (next->prev->n > next->n)
					swap_nodes(list, next->prev, next);
				else
					break;
			}
		}
		else
			current = current->next;
	}
}
