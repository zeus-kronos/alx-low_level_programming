#include "lists.h"
/**
* insert_dnodeint_at_index - insert  a node to a dlistint_t list.
* @h: double pointer to structure
* @idx: index of node to get from the list
* @n: data
* Return: the adrress of nth node, or NULL if it failed
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *tmp;
	unsigned int nth;

	new = (dlistint_t *)malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	if (idx == 0)
	{
		new->next = (*h);
		if (*h)
			(*h)->prev = new;
		(*h) = new;
		new->prev = NULL;
		return (new);
	}
	tmp = *h;
	nth = 0;
	while (tmp && nth < idx - 1)
	{
		nth++;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);
	new->next = tmp->next;
	new->prev = tmp;
	if (tmp->next)/*edge case*/
		tmp->next->prev = new;
	tmp->next = new;

	return (new);
}
