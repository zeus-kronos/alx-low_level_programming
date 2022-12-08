#include "lists.h"

/**
* print_dlistint - prints all the elements of a dlistint_t list
* @h: pointer to head of the dlistint_t list
* Return: number of nodes of dlistint_t list
*/

size_t print_dlistint(const dlistint_t *h)
{
	size_t num_of_nodes = 0;
	dlistint_t *current_node;

	if (!h)
		return (num_of_nodes);

	printf("%d\n", h->n);
	num_of_nodes++;
	current_node = h->next;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		num_of_nodes++;
		current_node = current_node->next;
	}

	return (num_of_nodes);
}
