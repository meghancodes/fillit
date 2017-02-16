#include "fillit.h"

void	solve(t_lst *tets)
{
	t_map *map;

	map = new_map(ceil_sqrt(tets->size));
	print_map(map);
}
