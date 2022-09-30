#include "main.h"

void print_array_elements(char *str);

/**
* main - Prints all arguments it receives
*
* @argc: Length of @argv, integer
*
* @argv: Array of strings of the arguments of this program
*
* Return: 0, success
*/

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		print_array_elements(argv[i]);
		_putchar('\n');
	}

	return (0);
}

/**
* print_array_elements - Prints all char of a string
*
* @str: Pointer to string
*
* Return: void
*/

void print_array_elements(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
