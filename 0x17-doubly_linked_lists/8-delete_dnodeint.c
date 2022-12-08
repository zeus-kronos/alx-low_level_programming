#include "lists.h"
/**
* delete_dnodeint_at_index - delet  a node in a given position
* @head: double pointer to structure
* @index: index of node to delete from the list
* Return: 1 sucess, -1 failure
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int nth = 0;

	tmp = *head;
	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		if (tmp->next)
			tmp->next->prev = NULL;
		(*head) = (*head)->next;
		free(tmp);
		return (1);
	}
	while (tmp && nth < index)
	{
		tmp = tmp->next;
		nth++;
	}
	if (tmp == NULL)
		return (-1);
	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);
	return (1);
}
