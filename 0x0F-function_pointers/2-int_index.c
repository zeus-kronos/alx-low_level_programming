#include "function_pointers.h"

/**
* int_index - Searches for an integer
*
* @array: An array of integers
*
* @size: Number of elements in the @array
*
* @cmp: Pointer to the function to be used to compare values
*
* Return: Integers, index integer in @array that matches
* condition of @cmp was found (SUCCESS) or
* -1 if size <= 0 or integer that matches condition of @cmp
*  wasn't found in @array or
*  NULL if @array || @cmp is NULL
*/

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0 || !array || !cmp)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
