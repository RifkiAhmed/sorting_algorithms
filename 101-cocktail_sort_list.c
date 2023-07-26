#include "sort.h"

/**
 * swap_nodes - swap two nodes in doubly linked list
 * @list: pointer to pointer to doubly linked list
 * @ptr1: pointer to 1st node
 * @ptr2: pointer to 2d node
 */
void swap_nodes(listint_t **list, listint_t *ptr1, listint_t *ptr2)
{
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
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: poiter to poiter to doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	char swapped;

	if (!list || !(*list)->next)
		return;

	current = *list;
	do {
		swapped = 'N';
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 'Y';
			}
			else
				current = current->next;
		}
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 'Y';
			}
			else
				current = current->prev;
		}
	} while (swapped == 'Y');
}
