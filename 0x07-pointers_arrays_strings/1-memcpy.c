#include "main.h"

/**
* _memcpy - copies n bytes from memory area
* @dest:char
* @src:char
* @n: unsigned
* Return: char
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int x;

for (x = 0; x < n; x++)
{
	dest[x] = src[x];
}
return (dest);
}
