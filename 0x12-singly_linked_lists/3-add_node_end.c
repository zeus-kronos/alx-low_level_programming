#include <string.h>
#include <stdio.h>
#include "lists.h"
#include "strlen.c"

list_t *createNewNode(const char *str);

/**
* add_node_end - dds a new node at the end of a list_t list
* @head: douple pointer to the head of the linked list
* @str: pointer to string to be assigned to the added node's str property
* Return: pointer to the new node (SUCCESS) OR
* NULL, if there is insufficent memory available (FAILURE)
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *current_node = *head;

	if (current_node)
	{
		while (current_node)
		{
			if (current_node->next)
			{
				current_node = current_node->next;
			}
			else
			{
				current_node->next = createNewNode(str);
				return (current_node->next);
			}
		}
	}
	else
	{
		*head = createNewNode(str);
	}

	return (*head);
}

/**
* createNewNode - create a new list_t list node
* @str: pointer to string to be assigned to the created node's str property
* Return: pointer to the new node (SUCCESS) OR
* NULL, if there is insufficent memory available (FAILURE)
*/

list_t *createNewNode(const char *str)
{
	list_t *new_node_ptr = malloc(sizeof(list_t));

	if (!new_node_ptr)
		return (NULL);

	new_node_ptr->str = strdup(str);

	if (!(new_node_ptr->str))
	{
		free(new_node_ptr);
		return (NULL);
	}

	new_node_ptr->len = _strLen(new_node_ptr->str);
	new_node_ptr->next = NULL;

	return (new_node_ptr);
}
