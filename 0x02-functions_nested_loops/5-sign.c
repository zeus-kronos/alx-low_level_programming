#include "main.h"

/**
 * print_sign - Code entry
 *
 * Description: A fuction that check if a number is a
 * negative, positive or zero integer.
 *
 * @n: The integer value it recieves
 *
 * Return: 0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}

	_putchar('0');
	return (0);
}
