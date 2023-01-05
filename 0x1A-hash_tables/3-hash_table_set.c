#include "hash_tables.h"

/**
 * str_copy - Creates a copy of a given string.
 * @s: The string to copy.
 *
 * Return: A pointer to the created string, otherwise NULL.
 */
char *str_copy(const char *s)
{
	int i, len;
	char *s_c = NULL;

	if (s != NULL)
	{
		len = strlen(s);
		s_c = malloc(sizeof(char) * (len + 1));
		if (s_c != NULL)
		{
			for (i = 0; i < len; i++)
				s_c[i] = s[i];
			s_c[i] = '\0';
		}
	}
	return (s_c);
}

/**
 * hash_table_set - Adds an element to a given hash table.
 * @ht: The hash table that will contain the element.
 * @key: The key of the element to add.
 * @value: The value of the element to add.
 *
 * Return: 1 if the addition was successful, otherwise 0.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long idx;
	hash_node_t *tmp = NULL, *new_node = NULL;

	if ((ht != NULL) && (ht->array != NULL)
		&& (key != NULL) && (strlen(key) > 0))
	{
		idx = key_index((unsigned char *)key, ht->size);
		tmp = ht->array[idx];
		while (tmp != NULL)
		{
			if (strcmp(tmp->key, key) == 0)
			{
				free(tmp->value);
				tmp->value = str_copy(value);
				return (1);
			}
			tmp = tmp->next;
		}
		tmp = ht->array[idx];
		new_node = malloc(sizeof(hash_node_t));
		if (new_node != NULL)
		{
			new_node->key = str_copy(key);
			new_node->value = str_copy(value);
			new_node->next = tmp;
			ht->array[idx] = new_node;
			return (1);
		}
	}
	return (0);
}
