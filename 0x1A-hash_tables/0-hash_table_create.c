#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table (as name implies) of size @size
 *
 * @size: The size of the hash table (the spaces allocated for nodes)
 * Return: pointer to the hash table on success, else, null
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	if (size < 1)
		return (NULL);

	ht = malloc(sizeof(hash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(hash_node_t *));

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	return (ht);
}
