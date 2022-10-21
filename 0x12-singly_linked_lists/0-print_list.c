#include <stdio.h>
#include "lists.h"

/**
* print_list - prints to standard output
* @h: A node in list_t
* Return: The number of nodes
*/

size_t print_list(const list_t *h)
{
	size_t num_of_nodes = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		num_of_nodes++;
	}
	return (num_of_nodes);
}
