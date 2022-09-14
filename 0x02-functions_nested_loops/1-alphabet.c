#include "main.h"

/**
 * print_alphabet - This function prints the alphabet in lowercase
 * followed by a new line
 */
void print_alphabet(void)
{
	int ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		_putchar(ch);
	}

	_putchar('\n');

}
