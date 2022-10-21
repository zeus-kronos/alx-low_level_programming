#include <stdlib.h>
#include <string.h>
#include "strlen.c"
#include "lists.h"

/**
* add_node - Adds a new node at the beginning of list_t list
* @new_head: Address of node
* @str: New node to add
* Return: Address of new element, NULL if it fails
*/

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node_ptr = malloc(sizeof(list_t));

	new_head = malloc(sizeof(list_t));

	if (new_head == NULL)
	{
		return (NULL);
	}
	else
	{
		new_head->str = strdup(str);
		new_head->len = length;
		new_head->next = *head;
		*head = new;
		return (new_head);
	}
}
