#include "sort.h"

/**
 * exchange_nodes - Exchange two nodes in listint_t doubly-linked list.
 * @h: This is the pointer to head of our doubly-linked list.
 * @nod1: A pointer to first node to be exchanged.
 * @nod2: The pointer to second node to be exchanged.
 */
void exchange_nodes(listint_t **h, listint_t **nod1, listint_t *nod2)
{
	(*nod1)->next = nod2->next;
	if (nod2->next != NULL)
		nod2->next->prev = *nod1;
	nod2->prev = (*nod1)->prev;
	nod2->next = *nod1;
	if ((*nod1)->prev != NULL)
		(*nod1)->prev->next = nod2;
	else
		*h = nod2;
	(*nod1)->prev = nod2;
	*nod1 = nod2->prev;
}

/**
 * insertion_sort_list - To sorts a doubly linked list of integers
 *                       by using the insertion sort algorithm.
 * @list: This is a pointer to head of a doubly-linked list of integers.
 *
 * Description: This will print out the list after each exchange.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = current->next;
		insert = current->prev;
		while (insert != NULL && current->n < insert->n)
		{
			exchange_nodes(list, &insert, current);
			print_list((const listint_t *)*list);
		}
	}
}
