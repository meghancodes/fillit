#include "fillit.h"
#include <stdio.h>
int		is_big_enough(t_map *map, t_tet *tet, int lines);

/*
** Check if the shape is one of the shapes that need extra dots
*/

int	check_shape(t_type *type)
{
	if (!ft_strcmp(type->name, "T2") || !ft_strcmp(type->name, "T3")
		|| !ft_strcmp(type->name, "J1")
		|| !ft_strcmp(type->name, "Z2") || !ft_strcmp(type->name, "S1"))
		return (1);
	if (!ft_strcmp(type->name, "L4"))
		return (2);
	return (0);
}

int check_around(t_map *map, int x, int y)
{
	if (x + 1 < map->size)
	{
		if (ft_isalpha(map->arr[x + 1][y]))
			return (1);
	}
	if (x - 1 >= 0)
	{
		if (ft_isalpha(map->arr[x - 1][y]))
			return (1);
	}
	if (y + 1 < map->size)
	{
		if (ft_isalpha(map->arr[x][y + 1]))
			return (1);
	}
	if (y - 1 >= 0)
	{
		if (ft_isalpha(map->arr[x][y - 1]))
			return (1);
	}
	return (0);
}

/*
** Checks top, right, bottom and left of each coordinate for a 1
** Also checks if the coordinates are okay for the tet
*/

int		valid_set(t_tet *tet, t_map *map, int x, int y)
{
	int i;
	int count;
	int lines;

	tet->x = x;
	tet->y = y;
	i = 0;
	count = 0;
	lines = check_shape(tet->type);
	if (lines > y || is_big_enough(map, tet, lines))
		return (0);
	if (is_empty_map(map))
		return (1);
	else
	{
		while (tet->type->shape[i] != '\0')
		{
			if (lines == 4)
			{
				x++;
				y = tet->y - check_shape(tet->type);
				lines = 0;
			}
			if (tet->type->shape[i] == '#')
			{
				if (map->arr[x][y])
					return (0);
				count += check_around(map, x, y);
				y++;
			}
			else if (tet->type->shape[i] == '.')
				y++;
			i++;
			lines++;
		}
	}
	if (count)
		return (1);
	return (0);
}

/*
** Checks whether the map is large enough to fit a shape at an XY
*/

int		is_big_enough(t_map *map, t_tet *tet, int lines)
{
	int x;
	int y;
	
	x = tet->x + tet->h;
	y = tet->y + tet->w - lines;
	if (x > map->size - 1 || y > map->size - 1)
	{
		if (x > y)
			return (x + 1);
		else
			return (y + 1);
	}
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
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (ft_isalpha(map->arr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	set_tet(t_tet *tet, t_map *map, int x, int y)
{
	int i;
	int lines;

	tet->x = x;
	tet->y = y;
	i = 0;
	lines = check_shape(tet->type);
	while (tet->type->shape[i] != '\0')
	{
		if (lines == 4)
		{
			x++;
			y = tet->y - check_shape(tet->type);
			lines = 0;
		}
		if (tet->type->shape[i] == '#')
		{
			map->arr[x][y] = tet->order;
			y++;
		}
		else if (tet->type->shape[i] == '.')
			y++;
		i++;
		lines++;
	}
	print_map(map);
}

// void	set_tet(t_tet *tet, t_map *map, int x, int y)
// {
// 	int i;
// 	int lines;

// 	tet->x = x;
// 	tet->y = y;
// 	i = 0;
// 	lines = check_shape(tet->type);
// 	while (tet->type->shape[i] != '\0')
// 	{
// 		if (lines == 4)
// 		{
// 			x++;
// 			y = tet->y - check_shape(tet->type);
// 			lines = 0;
// 		}
// 		if (tet->type->shape[i] == '#')
// 		{
// 			map->arr[x][y] = 1;
// 			y++;
// 		}
// 		else if (tet->type->shape[i] == '.')
// 			y++;
// 		i++;
// 		lines++;
// 	}
// 	//print_map(map);
// }
