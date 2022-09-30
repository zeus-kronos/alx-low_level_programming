#include "main.h"

int _atoi(char *s);
int multiply_two_nums(int num1, int num2);
void print_number(int n);

/**
* main - Entry point
*
* @argc: Length of @argv
*
* @argv: Array of strings of the arguments of this program
*
* Return: 0, Success
*/

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		print_number(multiply_two_nums(_atoi(argv[1]), _atoi(argv[2])));
		_putchar('\n');
		return (0);
	}
	else
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (0);
	}
}

/**
* _atoi - Convert a number in a string to an integer
*
* @s: String to be converted
*
* Return: Integer converted OR (0) if none
*/

int _atoi(char *s)
{
	int sign_cache = 1;
	int result = 0;

	while (s[0] != '\0')
	{
		if (s[0] == '-')
			sign_cache *= -1;
		else if (s[0] >= '0' && s[0] <= '9')
			result = (result * 10) + (s[0] - '0');
		else if (result)
			break;

		s++;
	}

	return (result * sign_cache);
}

/**
* multiply_two_nums - Multiplies two numbers
*
* @num1: A number
*
* @num2: A number
*
* Return: Result of num1 * num2
*/

int multiply_two_nums(int num1, int num2)
{
	return (num1 * num2);
}

/**
* print_number - Prints numbers chars
*
* @n: Integers params
*
* Return: 0
*/

void print_number(int n)
{
	unsigned int n1;

	n1 = n;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}

	if (n1 / 10 != 0)
	{
		print_number(n1 / 10);
	}

	_putchar((n1 % 10) + '0');
}
