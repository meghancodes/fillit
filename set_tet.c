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

/*
**  Checks whether first tet can fit inside empty map
**  (Calls in each coordinate of the tet_shape)
*/

int		is_big_enough(t_map *map, t_tet *tet)
{
	int lines;
	int max_x;
	int max_y;
	int y;
	int i;

	lines = 0;
	y = 0;
	max_x = 0;
	max_y = 0;
	i = 0;
	check_shape(tet->type, &lines);
	while (tet->type->shape[i] != '\0')
	{
	 if (lines == 4)
	 {
		 max_x++;
		 y = 0;
		 lines = 0;
	 }
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
		if (lines == 4)
		{
			x++;
			y = tet->y;
			lines = 0;
		}
		if (tet->type->shape[i] == '#')
		{
			map->arr[x][y] = 1;
			y++;
		}
		
		i++;
		lines++;
	}
}
