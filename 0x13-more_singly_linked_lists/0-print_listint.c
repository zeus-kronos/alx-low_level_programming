#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* print_listint - Prints all the elements of listint_t
* @h: Pointer to the head of the list
* Return: The number of node
*/

size_t print_listint(const listint_t *h)
{
	size_t num_of_nodes = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		num_of_nodes++;
	}
	return (num_of_nodes);
}
