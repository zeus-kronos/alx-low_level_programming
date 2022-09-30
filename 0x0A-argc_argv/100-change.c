#include <stdio.h>
#include <stdlib.h>

/**
* main - entry point
*
* @argc: integer, length of @argv
*
* @argv: one-dimensional array of strings, arguments of this program
*
* Return: 0, success
*/

int main(int argc, char *argv[])
{
	int result, amount, cent;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	result = 0;
	amount  = atoi(argv[1]);

	if (amount < 0)
	{
		printf("0\n");
		return (0);
	}

	while (amount)
	{
		if (amount >= 25)
			cent = 25;
		else if (amount >= 10)
			cent = 10;
		else if (amount >= 5)
			cent = 5;
		else if (amount >= 2)
			cent = 2;
		else
			cent = 1;

		result += amount / cent;
		amount %= cent;
	}

	printf("%d\n", result);
	return (0);
}
