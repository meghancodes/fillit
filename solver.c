#include "fillit.h"

void	solve(t_lst *tets)
{
	t_map	*map;
	int		x;
	int		y;

	map = new_map(ceil_sqrt(tets->size));
	print_map(map);
	x = 0;
	y = 0;
//	if(valid_set(tets->head, map, x, y))
//		set_tet(tets->head, map, x, y);
//	print_map(map);
}
