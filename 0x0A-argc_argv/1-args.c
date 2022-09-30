#include "main.h"

void print_number(int num);

/**
* main - Prints the number of arguments passed into it
*
* @argc: Length of @argv
*
* @argv: Array of strings of the programs arguments
*
* Return: 0, Success
*/

int main(int argc, char *argv[] __attribute__((unused)))
{
	print_number(--argc);
	_putchar('\n');
	return (0);
}

/**
* print_number - prints number with _putchar
*
* @num: inter, number to be printed
*
* Return: void
*/

void print_number(int num)
{
	if (num / 10)
		print_number(num / 10);

	_putchar(num % 10 + '0');
}
