#include "fillit.h"

void	solve(t_lst *tets)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return ;
	map = new_map(ceil_sqrt(tets->size));
	print_map(map);
	int x = 0;
	int y = 0;
//	ft_putchar('\n');
//	print_map(map);
//	if(valid_set(tets->head, map, x, y))
	set_tet(tets->head, map, x, y);
	print_map(map);
}
