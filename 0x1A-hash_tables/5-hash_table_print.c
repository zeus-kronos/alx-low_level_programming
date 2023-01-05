#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: hash table
 * Return: void
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i, move = 0;

	if (!ht)
		return;


	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		if (move == 1 && node != NULL)
			printf(", ");
		if (node)
		{
			if (!(node->next))
			{
				printf("'%s': '%s'", node->key, node->value);
				move = 1;
				continue;
			}
			while (node)
			{
				move = 1;
				printf("'%s': '%s'", node->key, node->value);
				if (node->next)
					printf(", ");
				node = node->next;
			}
		}
	}
	printf("}\n");
}
