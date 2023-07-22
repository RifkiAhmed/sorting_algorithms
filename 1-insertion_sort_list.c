#include "sort.h"

/**
 * nodes_number - counts number of nodes in doubly linked list
 *
 * @list: pointer to the pointer to doubly linked list
 *
 * Return: Number of nodes
 */
int nodes_number(listint_t **list)
{
	listint_t *tmp;
	int count = 0;

	tmp = *list;
	if (tmp)
		count++;
	while (tmp = tmp->next)
		count++;
	return (count);
}

/**
 * swap - swaps two nodes
 *
 * @list: pointer to the pointer to doubly linked list
 * @ptr1: pointer to 1st node
 * @ptr2: pointer to 2d node
 */
void swap(listint_t **list, listint_t *ptr1, listint_t *ptr2)
{
	/** ptr1->n > ptr2->n */
	if (ptr1->prev)
		ptr1->prev->next = ptr2;
	if (ptr2->next)
		ptr2->next->prev = ptr1;
	ptr1->next = ptr2->next;
	ptr2->prev = ptr1->prev;
	ptr1->prev = ptr2;
	ptr2->next = ptr1;
	if (!ptr2->prev)
		*list = ptr2;
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

	if (list == NULL || nodes_number(list) < 2)
		return;
	current = *list;
	while (current->next)
	{
		next = current->next;
		if (current->n > next->n)
		{
			swap(list, current, next);
			print_list(*list);
			while (next->prev)
			{
				if (next->prev->n > next->n)
				{
					swap(list, next->prev, next);
					print_list(*list);
				}
				else
					break;
			}
		}
		else
			current = current->next;
	}
}
