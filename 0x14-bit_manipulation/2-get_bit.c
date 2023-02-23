#include "main.h"

/**
 * get_bit - return one bit
 * @n: the number
 * @index: the position to read the bit
 * Description: return 1 bit
 * section header: the header of this function is main.h
 * Return: the value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit;

	if (index > 64)
		return (-1);

	bit = n >> index;

	return (bit & 0x1);
}
