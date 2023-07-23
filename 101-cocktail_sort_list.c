#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly
 * linked list
 * @list: pointer to the head of the list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1, *next2;

	if (!list || !node1 || !node2)
		return;

	prev1 = node1->prev;
	next2 = node2->next;

	if (prev1)
		prev1->next = node2;
	else
		*list = node2;

	if (next2)
		next2->prev = node1;

	node2->prev = prev1;
	node1->next = next2;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Cocktail
 * shaker sort algorithm
 * @list: pointer to the head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current && current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		current = current->prev;
		while (current && current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
