#include "fillit.h"

int		valid_set(t_tet *node, t_map *map)
{
	//a function to recognize the tet type

	if (map->arr[x][y] == 1)
		return (0);
	else if (map->arr[x][y] == 0 && map->arr[x + 1][y + 1] == 1 || )
		place_shape;
	if (*node )
	return (1);
}

void	set_tet(t_tet *node, t_map *map, int x, int y)
{
	node->x = x;
	node->y = y;
	map->arr[x][y] = 1; //need to set the rest of the shape to 1
}
