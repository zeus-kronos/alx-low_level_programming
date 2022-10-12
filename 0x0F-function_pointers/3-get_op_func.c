#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
* get_op_func - Selects correct function to perform based on @s
*
* @s: The operator
*
* Return: The pointer to the operator's function or
* NULL if not found
*/

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;

	while (i < 5)
	{
		if (*(ops[i].op) == *s)
			return (ops[i].f);

		i++;
	}

	return (ops[i].f);
}
