#include <stdlib.h>

/**
* argstostr - Concatenates all the arguments of the program
*
* @ac: Argument total count
*
* @av: Pointer to arguments
*
* Return: Pointer to concatenated string (SUCCESS) or
* NULL if @ac == 0 or @av == NULL (FAILURE) or
* NULL if if insufficient memory was available (FAILURE)
*/

char *argstostr(int ac, char **av)
{
	int i, j;
	int count = 0;
	int t_count = 0;
	char *result;

	if (ac == 0 || av == NULL)
		return ('\0');

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			t_count++;

		t_count++;
	}

	result = malloc(sizeof(char) * t_count + 1);

	if (result == NULL)
	{
		return ('\0');
	}

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			result[count++] = av[i][j];
		}
		result[count++] = '\n';
	}

	result[t_count] = '\0';
	return (result);
}
