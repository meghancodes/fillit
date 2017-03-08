#include "fillit.h"

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
		if (is_big_enough(map, list->current))
		{
			new_size = is_big_enough(map, list->current);
			ft_bzero(map, sizeof(map));
			map = new_map(new_size);
		}
		else
		{
			int x = 0;
			int y = 0;
			ft_bzero(map, sizeof(map));
			map = new_map(ceil_sqrt(list->size));
			set_tet(list->current, map, x, y);
			print_map(map);
		}
		list->current = list->current->next;
	}
}
