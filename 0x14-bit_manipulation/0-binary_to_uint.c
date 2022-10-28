#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
* _strlen - find the length of a string
* @s: pointer to the string to check
* Return: void
*/


int _strlen(const char *s)
{
int i = 0;
while (s[i])
	i++;

return (i);
}


/**
* binary_to_uint - converts a binary number to an unsigned int
* @b: binary number
*
* Return: 0 or converted number
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;
	int i, len;

	if (b == NULL)
		return (0);

	len = _strlen(b);

	for (i = 0; i != len; i++)
	{
		if (b[len - i - 1] == '1')
			n += 1 << i;
		else if (b[len - i - 1] != '0')
			return (0);
	}

	return (n);
}
