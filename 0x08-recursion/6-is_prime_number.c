#include "main.h"

/**
* prime_check - Checks to see if number is prime
*
* @f: Factor check
*
* @p: Possible prime number
*
* Return: 1 if prime, 0 if not
*
*/

int prime_check(int f, int p)
{
	if (p < 2 || p % f == 0)
		return (0);
	else if (f > p / 2)
		return (1);
	else
		return (prime_check(f + 1, p));
}

/**
* is_prime_number - States if number is prime
*
* @n: Number to check
*
* Return: 1 if prime, 0 if not
*/

int is_prime_number(int n)
{
	if (n == 2)
		return (1);
	return (prime_check(2, n));
}
