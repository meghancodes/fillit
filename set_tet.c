#include "fillit.h"
#include <stdio.h>

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

/*
**  Checks top, right, bottom and left of each coordinate for a 1
*/

// int		valid_set(t_tet *node, t_map *map, int x, int y)
// {
// 	int i;
// 	int count;
// 	unsigned int tmp_x;
// 	unsigned int tmp_y;

// 	node->x = x;
// 	node->y = y;
// 	tmp_x = x;
// 	tmp_y = y;
// 	i = 0;
// 	count = 0;
// 	if (is_empty_map(map))
// 	{
// 		ft_putstr("empty map confirmed\n");
// 		return (1);
// 	}
// 	if (!is_empty_map(map))
// 	{
// 		ft_putstr("The map isnt empty\n");
// 		if (map->arr[x][y] == 0)
// 		{
// 			while (tet->type->shape != '\0')
// 			{
// 				if (map->arr[x + node->type[i][1]][(y + node->type[i][0])-1] != 1 || map->arr[(x + node->type[i][1])+1][y + node->type[i][0]] != 1
// 					|| map->arr[x + node->type[i][1]][(y + node->type[i][0])+1] != 1 || map->arr[(x + node->type[i][1])-1][y + node->type[i][0]] != 1)
// 					count++;
// 				if (tmp_x > map->size)
// 			}
// 		}	 
// 	}
// 	if (count >= 1)
// 		return (1);
// 	ft_putstr("Valid set works \n");
// 	return (0);
// }

int		is_big_enough(t_map *map, t_tet *tet)
{
	int lines;
	int max_x;
	int max_y;
	int y;
	int i;

	lines = 0;
	y = tet->y;
	max_x = tet->x;
	max_y = tet->y;
	i = 0;
	lines = check_shape(tet->type);
	while (tet->type->shape[i] != '\0')
	{
	 if (lines == 4)
	 {
		 max_x++;
		 y = tet->y - check_shape(tet->type);
	 }
//	 if (!ft_strcmp(tet->type->name, "Z1") && i == 4)
//	 	y = 1;
//	 if (!ft_strcmp(tet->type->name, "S1") && i == 3)
//	 	y = 1;
	 if (tet->type->shape[i] == '#')
	 {
		 y++;
		 if (y > max_y)
			 max_y = y;
	 }
	 
	 i++;
	 lines++;
	}
	max_x++;
	if (max_x > (map->size) || max_y > (map->size))
	{
		if (max_x > max_y)
			return (max_x);
		else
			return (max_y);
	}
	return (0);
}


/*
**  Checks if each tet can fit inside current map->size
**  If not calls for a bigger map
*/

// int can_tet_fit()
// {

// }

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

void	set_tet(t_tet *tet, t_map *map, int x, int y)
{
	int i;
	int lines;

	tet->x = x;
	tet->y = y;
	i = 0;
	lines = check_shape(tet->type);
	printf("%s\n", tet->type->name);
	while (tet->type->shape[i] != '\0')
	{
		if (lines == 4)
		{
			x++;
			y = tet->y - check_shape(tet->type);
			lines = 0;
			//lines = check_shape(tet->type);
		}
		if (tet->type->shape[i] == '#')
		{
			map->arr[x][y] = 1;
			y++;
		}
		else if (tet->type->shape[i] == '.')
		{
			y++;
		}
		i++;
		lines++;
	}
}

