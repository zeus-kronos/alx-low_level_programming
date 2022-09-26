#include "main.h"

/**
* _strchr - locates a character in a string
* @s : char
* @c : char
* Return: char
*/

char *_strchr(char *s, char c)
{
for (;; s++)
{
	if (*s == c)
		return (s);

	if (*s == '\0')
		return ('\0');
}

return (0);

}
