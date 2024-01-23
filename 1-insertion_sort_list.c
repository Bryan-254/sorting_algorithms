#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *iterator;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		iterator = current->prev;
		while (iterator != NULL && iterator->n > current->n)
		{
			iterator->next = current->next;
			if (current->next != NULL)
				current->next->prev = iterator;
			current->prev = iterator->prev;
			current->next = iterator;
			iterator->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
			iterator = current->prev;
		}
		current = next;
	}
}
