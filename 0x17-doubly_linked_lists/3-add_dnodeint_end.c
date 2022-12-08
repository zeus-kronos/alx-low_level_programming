#include "lists.h"

dlistint_t *_add_dnodeint(dlistint_t **head, const int n);

/**
* add_dnodeint_end - adds a new node at the end of a dlistint_t list
* @head: double pointer to head of the list
* @n: value n of the new node to be added to the list
* Return: address of the new element, or NULL if it failed
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *current_node;

	if (!(*head))
		return (_add_dnodeint(head, n));

	new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	current_node = *head;

	while (current_node->next)
		current_node = current_node->next;

	current_node->next = new_node;
	new_node->prev = current_node;

	return (new_node);
}

/**
* _add_dnodeint - adds a new node at the beginning of a dlistint_t list
* @head: double pointer to the head of the list
* @n: value n of the new node to be added to the list
* Return:  the address of the new element, or NULL if it failed
*/

dlistint_t *_add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}
