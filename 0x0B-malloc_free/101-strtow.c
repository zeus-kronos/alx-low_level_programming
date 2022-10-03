#include <stdlib.h>
#include "main.h"

/**
* **strtow - function that splits a string into words.
* @str : pointer
* Return: Char
*/

char **strtow(char *str)
{
	char **d;
	int i;
	int j = 0;
	int con = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] != 32)
			con++;
	}

	d = malloc(sizeof(char) * con);

	if (d == NULL)
		return (NULL);

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] != 32)
		{
			*d[j] = str[i];
			j++;
		}
		else
		{
		}
	}
	return (d);
}
