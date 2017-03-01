#include "fillit.h"

/*
** Check if the shape is one of the shapes that need extra dots
*/

void	check_shape(t_type *type, int *lines)
{
	char one_dot[5][2] = {"T2", "T3", "J1", "Z2", "S1"};
	int i;

	i = 0;
	while (i < 5)
	{
		if (!ft_strcmp(type->name, one_dot[i]))
			*lines += 1;
		i++;
	}
	if (!ft_strcmp(type->name, "L4"))
		*lines += 2;
}

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
/*			if (map->arr[x + node->type[i][1]][y + node->type[i][0]] == 0)
			{
				if (map->arr[x + node->type[i][1]][(y + node->type[i][0])-1] != 1 || map->arr[(x + node->type[i][1])+1][y + node->type[i][0]] != 1
					|| map->arr[x + node->type[i][1]][(y + node->type[i][0])+1] != 1 || map->arr[(x + node->type[i][1])-1][y + node->type[i][0]] != 1)
					count++;
			} */
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
void	set_tet(t_tet *tet, t_map *map, int x, int y)
{
	int i;
	int lines;

	tet->x = x;
	tet->y = y;
	i = 0;
	lines = 0;
	check_shape(tet->type, &lines);
	while (tet->type->shape[i] != '\0')
	{
		ft_putnbr(lines);
		ft_putstr(" inside loop\n");
		if (tet->type->shape[i] == '#')
		{
			ft_putstr("inside first if\n");
			set_map_val(map, x, y);
			ft_putstr("Placed 1\n");
		}
		else if (lines % 4 == 0)
		{
			x++;
			y = tet->y;
		}
		else
			y++;
		i++;
		lines++;
	}
}
