#include "hash_tables.h"

/**
 * hash_table_create - Function that creates a hash table.
 * @size: size of the array.
 *
 * Return: pointer to the hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *newtable;
	hash_node_t **node;

	newtable = calloc(1, sizeof(hash_table_t));
	if (newtable == NULL)
		return (NULL);

	newtable->size = size;
	newtable->array = calloc(size, sizeof(node));

	if (newtable->array == NULL)
		return (NULL);
	return (newtable);
}
