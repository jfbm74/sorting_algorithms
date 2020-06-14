#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list to sort
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *pivot;

	if (list == NULL || *list == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		pivot = current->next;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = pivot;
	}
}
