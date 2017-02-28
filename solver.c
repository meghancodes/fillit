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
	ft_putstr(tets->head->type->shape);
	ft_putchar('\n');
	ft_putstr(tets->head->type->name);
	ft_putchar('\n');
//	if(valid_set(tets->head, map, x, y))
//		set_tet(tets->head, map, x, y);
//	print_map(map);
}
