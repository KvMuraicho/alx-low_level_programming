#include <stdlib.h>

/**
 * free_grid - Frees a 2-dimensional grid created by the alloc_grid function.
 * @grid: the 2D grid/array to be freed.
 * @height: the height of the grid (i.e., number of rows).
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}

