#include <stdlib.h>

/**
* free_grid - Free a 2 dimensional grid previously created by your
* alloc_grid function
*
* @grid: The grid we'll free up
* @height: The number of rows in the grid
*
* Return: Nothing
*/

void free_grid(int **grid, int height)
{
	int i = 0;

	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
