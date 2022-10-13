#include "function_pointers.h"

/**
* print_name - prints a name
* @name: name to print
* @f: pointer to a function
*
* Description: prints a name using function pointers
* Return: void
*/

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
