#include "lists.h"

/**
* free_listint - Frees a list_t list
* @head: Pointer to the head/first node of list_t
*/

void free_listint(listint_t *head)
{
	listint_t *placeholder;

	while (head)
	{
		placeholder = head->next;
		free(head);
		head = placeholder;
	}
}
