#include "main.h"
/**
 * print_binary - decimal to binary without use / %
 * @n: the decimal
 * Description: convert decimal to binary
 * section header: the header of this function is main.h
 * Return: no return
 */
void print_binary(unsigned long int n)
{
	int flag = 0;
	unsigned long int mask = 1;

	mask <<= 63;
	if (n == 0)
		_putchar('0');

	while (mask > 0)
	{
		if ((n & mask) == 0 && flag == 1)
			_putchar('0');
		if ((n & mask) != 0)
		{
			_putchar('1');
			flag = 1;
		}

		mask = mask >> 1;
	}
}
