#include "fillit.h"

int		solve(t_tet *tet, t_map *map)
{
	int		row;
	int		col;
	t_tet	*save;

	row = 0;
	save = tet;
	if (!save)
		return (1);
	while (row < map->size - save->h)
	{
		col = 0;
		while (col < map->size - save->w)
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
