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
	{
		// if (is_big_enough(map, node))
		// {
		// 	ft_putstr("does this work?\n");
		// 	return (1);
		// }
		return (1);
	}
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
		if (count >= 1)
			return (1);
	}
	ft_putstr("Valid set works \n");
	return (0);
}

/*
**  Checks if map is empty
*/

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

/*
**  Checks whether first tet can fit inside empty map
**  (Calls in each coordinate of the tet_shape)
*/

// int		is_big_enough(t_map *map, t_tet *node)
// {
// 	int i;
// 	int x;
// 	int y;

// 	i = 0;
// 	x = 0;
// 	y = 0;
// 	while (i++ < 4)
// 	{
// 		ft_putstr("does this part work?\n");
// 		if (map->arr[x + node->type[i][0]][y + node->type[i][1]] == 0)
// 		{
// 			ft_putstr("map not big enough\n");
// 			return (0);
// 		}
// 	}
// 	return (1);
// }
//
// Basically set_tet is using the string to loop through and make the shape instead of using coordinates. The only issue should be in the shapes that needed dots before them so that's why I saved the shape name to be able to quickly identify the shape. Maybe should write a separate function to do this
void	set_tet(t_tet *tet, t_map *map, int x, int y)
{
	int i;

	tet->x = x;
	tet->y = y;
	i = 0;
	while (tet->type->shape[i] != '\0')
	{
		if (tet->type->shape[i] == '#')
			map->[x][y] = 1;
		else if (i % 4 = 0)
		{
			x++;
			y = tet->y;
		}
		else
			y++;
	}
	map->size = map->size;
}
