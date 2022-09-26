#include "main.h"

/**
* _memset - fills memory with a constant byte
* @s: memory space to be filled
* @b: byte to fill with
* @n: number of spaces to fill
*
* Return: pointer to memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}
	return (s);
}
