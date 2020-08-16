#include "sandpiles.h"


void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int next_sandpile[3][3];

	sum_grids(grid1, grid2);

	while (stable_grid(grid1) != 0)
	{
		printf("=\n");
		print_grid_este(grid1, next_sandpile);
		topple(grid1, next_sandpile);
		sum_grids(grid1, next_sandpile);
	}

}

int stable_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}

	return (0);
}

void topple(int grid[3][3], int next_sandpile[3][3])
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
				next_sandpile[x][y] -= 4;

				next_sandpile[x][y - 1] += (y - 1) >= 0 ? 1 : 0;
				next_sandpile[x + 1][y] += (x + 1) < 3 ? 1 : 0;
				next_sandpile[x - 1][y] += (x - 1) >= 0 ? 1 : 0;
				next_sandpile[x][y + 1] += (y + 1) < 3 ? 1 : 0;
			}
		}
	}
}

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

void print_grid_este(int grid[3][3], int next_sandpile[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			next_sandpile[i][j] = 0;
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
