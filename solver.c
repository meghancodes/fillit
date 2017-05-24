#include "fillit.h"

/*
**  Zero out map array
*/

void	zero_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			map->arr[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		solve(t_tet *tet, t_map *map)
{
	int		row;
	int		col;
	t_tet	*save;

	row = 0;
	save = tet;
	// Base case for recursion, when it reaches the end of the list of tets
	if (!save)
		return (1);
	while (row < map->size - save->h + 1)
	{
		col = 0;
		while (col < map->size - save->w + 1)
		{
			if (valid_set(save, map, row, col))
			{
				if (solve(set_tet(save, save->order, map, row, col), map))
					return (1);
				unset_tet(map, save);
			}
			col++;
		}
		row++;
	}
	return (0);
}
