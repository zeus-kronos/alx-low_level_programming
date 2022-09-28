#include "main.h"

/**
* factorial - Returns the factorial of a given number @n
*
* @n: The number
*
* Return: An integer, the result of @n factorial
*/

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
