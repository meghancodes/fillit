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

void	solve(t_lst *list)
{
	t_map	*map;
	int		new_size;

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
	while (list->current != NULL)
	{
		int x = 0;
		int y = 2;
		list->current->x = x;
		list->current->y = y;
		while (is_big_enough(map, list->current))
		{
			new_size = is_big_enough(map, list->current);
			ft_bzero(map, sizeof(map));
			map = new_map(new_size);
		}
		zero_map(map);
		set_tet(list->current, map, x, y);
		print_map(map);
		list->current = list->current->next;
	}
}
