#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list to sort
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *pivot;

	head = pivot = *list;
	while (pivot->next != NULL)
	{
		pivot = pivot->next;
		if (head->n > pivot->n)
		{
			while (pivot->n < head->n)
			{
				if (head->prev == NULL)
				{
					(pivot->next)->prev = head;
					head->next = pivot->next;
					head->prev = pivot;
					pivot->next = head;
					pivot->prev = NULL;
					*list = pivot;
					pivot = head;
				}
				else if (pivot->next == NULL)
				{
					pivot->prev = head->prev;
					pivot->next =  head;
					head->next = NULL;
					head->prev = pivot;
					(pivot->prev)->next = pivot;
					head = head->prev->prev;
				}
				else
				{
					(head->prev)->next = pivot;
					(pivot->next)->prev = head;
					head->next = pivot->next;
					pivot->prev = head->prev;
					pivot->next = head;
					head->prev = pivot;
					head = head->prev->prev;
				}
				print_list(*list);
			}
		}
		head = pivot;
	}
}
