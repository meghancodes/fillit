#include "fillit.h"

//Zero out map array
void	zero_map(t_map *map)
{
	int i;
	int j = 0;
	
	i = 0;
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


/*
** Rotates the list of tets forward one
** Last tet->next = first tet
** Last tet = head
** Second to last tet->next = NULL
*/

void rot_list(t_lst *list)
{
	int i;
	
	i = 0;
	list->current = list->head;
	while (i < list->size - 1)
	{
		list->current = list->current->next;
		i++;
	}
	list->current->next = list->head;
	list->head = list->current;
	i = 0;
	while (i < list->size - 1)
	{
		list->current = list->current->next;
		i++;
	}
	list->current->next = NULL;
	list->current = list->head;
}

int solve(t_tet *tet, t_map *map)
{
	int		x;
	int		y;
	t_tet	*save;
	
	x = 0;
	save = tet;
	if (!save)
		return (1);
	while (x < map->size - tet->h)
	{
		y = 0;
		while (y < map->size - tet->w)
		{
			if (valid_set(save, map, x, y))
			{
				print_map(map);
				ft_putchar('\n');
				if (solve(set_tet(save, save->order, map, x, y), map))
				{
					ft_putstr("Final Solution\n");
					return (1);
				}
				unset_tet(map, save);
			}
			y++;
		}
		x++;
	}
	return (0);
}