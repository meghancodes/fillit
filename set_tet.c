#include "fillit.h"

/*
**  Checks top, right, bottom and left of each coordinate for a 1
*/

int		valid_set(t_tet *node, t_map *map, int x, int y)
{
	int i;
	int count;

	node->x = x;
	node->y = y;
	i = 0;
	count = 0;
	if (is_empty_map(map))
		return (1);
	if (!is_empty_map(map))
	{
		ft_putstr("The error isn't here\n");
		while (i++ < 4)
		{
			if (map->arr[x + node->type[i][1]][y + node->type[i][0]] == 0)
			{
				if (map->arr[x + node->type[i][1]][(y + node->type[i][0])-1] != 1 || map->arr[(x + node->type[i][1])+1][y + node->type[i][0]] != 1
					|| map->arr[x + node->type[i][1]][(y + node->type[i][0])+1] != 1 || map->arr[(x + node->type[i][1])-1][y + node->type[i][0]] != 1)
					count++;
			}
		}
	}
	ft_putstr("Valid set works \n");
	if (count >= 1)
		return (1);
	return (0);
}

int		is_empty_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i++ < map->size)
	{
		j = 0;
		while (j++ < map->size)
		{
			if (map->arr[i][j] != 0)
				return (0);
		}
	}
	return (1);
}

void	set_tet(t_tet *node, t_map *map, int x, int y)
{
	int i;

	node->x = x;
	node->y = y;
	i = 0;
	while (i < 4)
	{
		ft_putstr("inside loop\n");
		ft_putnbr(node->type[i][1]);
		ft_putnbr(node->type[i][0]);
		i++;
	}
	map->size = map->size;
}
