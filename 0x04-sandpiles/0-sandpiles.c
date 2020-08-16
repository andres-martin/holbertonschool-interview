#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int masking_grid[3][3];

	sum_grids(grid1, grid2);

	while (stable_grid(grid1) != 0)
	{
		printf("=\n");
		print_and_set_grid(grid1, masking_grid);
		topple(grid1, masking_grid);
		sum_grids(grid1, masking_grid);
	}

}

/**
 * stable_grid - checks if gird is stable
 * @grid: grid 3x3
 *
 * Return: 1 if unstable 0 otherwise
 */

int stable_grid(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
				return (1);
		}
	}

	return (0);
}

/**
 * topple - topples grid
 * @grid: grid 3x3
 * @masking_grid: mask to add to main grid
 *
 */

void topple(int grid[3][3], int masking_grid[3][3])
{
	int x, y;
	int value = 0;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			value = grid[x][y];
			if (value > 3)
			{
				masking_grid[x][y] -= 4;

				masking_grid[x][y - 1] += (y - 1) >= 0 ? 1 : 0;
				masking_grid[x + 1][y] += (x + 1) < 3 ? 1 : 0;
				masking_grid[x - 1][y] += (x - 1) >= 0 ? 1 : 0;
				masking_grid[x][y + 1] += (y + 1) < 3 ? 1 : 0;
			}
		}
	}
}

/**
 * sum_grids - adds two grid
 * @grid1: grid 3x3
 * @grid2: grid 3x3
 */

void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int x, y = 0;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
		}
	}
}

/**
 * print_and_set_grid - self descriptive
 * @grid: 3x3 array
 * @masking_grid: self descriptive
 */

void print_and_set_grid(int grid[3][3], int masking_grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			masking_grid[i][j] = 0;
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
