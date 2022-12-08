#include "lists.h"
/**
* free_dlistint - frees a dlistint_t list
* @head: pointer to head of the dlistint_t list to be freed
*/

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node = head, *free_temp;

	if (!head)
		return;

	while (current_node->next)
	{
		free_temp = current_node;
		current_node = current_node->next;
		free(free_temp);
	}

	free(current_node);
}
