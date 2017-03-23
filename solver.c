#include "fillit.h"

//Zero out map array
void	zero_map(t_map *map)
{
	int i;
	int j;
	
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			map->arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

int solve(t_lst *tets, t_map *map)
{
	int x;
	int y;
	
	x = 0;
	while (tets->current->next != NULL && x < map->size)
	{
		y = 0;
		while (y < map->size)
		{
			if (valid_set(tets->current, map, x, y))
			{
				set_tet(tets->current, map, x, y);
				tets->current = tets->current->next;
				if (solve(tets, map))
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

/* void	solve(t_lst *list)
{
	t_map	*map;
	int		new_size;
	// int x = 0;
	// int y = 0;
	int i = 0;
	int j;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return ;
	map = new_map(ceil_sqrt(list->size));
	// print_map(map);
//	int x = 0;
//	int y = 0;
//	ft_putchar('\n');
//	print_map(map);
//	if(valid_set(tets->head, map, x, y))
	//set_tet(list->head, map, x, y);
	//print_map(map);
	list->current = list->head;
	while (is_big_enough(map, list->current))
	{
		new_size = is_big_enough(map, list->current);
		ft_bzero(map, sizeof(map));
		map = new_map(new_size);
	}
	while (list->current != NULL)
	{
		while (i < map->size)
		{
			j = 0;
			while (j < map->size)
			{
				if (!map->arr[i][j])
				{
					list->current->x = i;
					list->current->y = j;
					if (valid_set(list->current, map, list->current->x, list->current->y))
						set_tet(list->current, map, list->current->x, list->current->y);
				}
				j++;
			}
			i++;
		}
		// zero_map(map);
		list->current = list->current->next;
	}
} */
