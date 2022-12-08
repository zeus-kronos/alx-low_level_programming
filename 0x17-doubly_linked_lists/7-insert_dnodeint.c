#include "lists.h"

void add_in_middle(dlistint_t *node_at_choice_index, dlistint_t *new_node);
void add_at_the_end(dlistint_t *node_b4_null, dlistint_t *new_node);
dlistint_t *create_new_node(int n);

/**
* insert_dnodeint_at_index - inserts a new node at a given position
* @h: double pointer to the head of the list
* @idx: index of the list where the new node should be added
* @n: elemenent of the new node to be added at @idx
* Return: the address of the new node, or NULL if it failed
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current_node_at_the_index = NULL, *new_node, *c_node, *prev;
	unsigned int i = 0;

	if (!(*h))
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	c_node = *h;

	while (c_node)
	{
		if (i == idx)
		{
			current_node_at_the_index = c_node;
			break;
		}

		prev = c_node;
		c_node = c_node->next;
		i++;
	}

	if (!current_node_at_the_index && (i != idx))
		return (NULL);

	new_node = create_new_node(n);

	if (!new_node)
		return (NULL);

	if (!current_node_at_the_index && (i == idx))
		add_at_the_end(prev, new_node);
	else
		add_in_middle(current_node_at_the_index, new_node);

	return (new_node);
}

/**
* add_in_middle - adds a node in between nodes of dlistint_t list
* @node_at_choice_index: pointer to the node at index of insertion
* @new_node: pointer to new node
*/

void add_in_middle(dlistint_t *node_at_choice_index, dlistint_t *new_node)
{
	new_node->prev = node_at_choice_index->prev;
	new_node->next = node_at_choice_index;

	(node_at_choice_index->prev)->next = new_node;
	node_at_choice_index->prev = new_node;
}

/**
* add_at_the_end - adds a node to end of dlistint_t list
* @node_b4_null: pointer to node before end null node
* @new_node: pointer to new node
*/

void add_at_the_end(dlistint_t *node_b4_null, dlistint_t *new_node)
{
	node_b4_null->next = new_node;
	new_node->prev = node_b4_null;
	new_node->next = NULL;
}

/**
* create_new_node - creates a new node for dlistint_t list
* @n: elemenent of the new node
* Return: pointer to a new node
*/

dlistint_t *create_new_node(int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;

	return (new_node);
}
