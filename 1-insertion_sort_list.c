#include "sort.h"

/**
 * swapnode - swaps two nodes in a doubly linked list
 *
 * @h: pointer to head of doubly linked list
 * @n1: pointer to node that is to be swapped
 * @n2: second node to be swapped
 *
 * Return: swapped nodes
 */

void swapnode(listint_t **h, listint_t **n1, listint_t *n2)
{
	if (n1 == NULL || n2 == NULL || *n1 == n2)
		return;
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts integers in ascending order with insertion
 *
 * @list: double pointer to doubly linked list
 *
 * Return: sorted array
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		j = i->prev;
		while (j != NULL && i->n < j->n)
		{
			swapnode(list, &j, i);
			print_list((const listint_t *)*list);
		}
	}
}
