#include "fillit.h"

void	set_tet(t_tet *node, t_map *map, int x, int y)
{
	node->x = x;
	node->y = y;
	map->arr[x][y] = 1; //need to set the rest of the shape to 1
}
