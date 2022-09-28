#include "main.h"

/**
* _pow_recursion - Returns the value of x raised to the power of y
*
* @x: An integer
*
* @y: An integer --> power of @x
*
* Return: Value of @x raised to the power of @y
*/

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
