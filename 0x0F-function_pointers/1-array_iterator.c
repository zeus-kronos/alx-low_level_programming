#include <stdio.h>
#include "function_pointers.h"

/**
* array_iterator - Executes a function as a parameter
* on each element of an array
*
* @array: An array of paramters (values) to be passed to @action
*
* @size: Size/length of @array
*
* @action: Pointer to a function
*/

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!action || !array)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
