#include "fillit.h"
#include <stdio.h>

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
	int		row;
	int		col;
	t_tet	*save;
	
	row = 0;
	save = tet;
	// Base case for recursion, when it reaches the end of the list of tets
	if (!save)
		return (1);
	while (row < map->size - save->h)
	{
		col = 0;
		while (col < map->size - save->w)
		{
			if (valid_set(save, map, row, col))
			{
				// print_map(map);
				// ft_putchar('\n');
				if (solve(set_tet(save, save->order, map, row, col), map))
					return (1);
				// printf("Reset board: %c\n", save->order);
				unset_tet(map, save);
				// printf("\n");
			}
			col++;
		}
		row++;
	}
	return (0);
}