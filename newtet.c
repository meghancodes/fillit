#include "fillit.h"

t_tet		*newtet(char type, int order, int x, int y)
{
	t_tet	new;

	new = malloc(sizeof(t_tet));
	if (new)
	{
		new->type = type;
		new->order = order;
		new->x = x;
		new->y = y;
	}
	return (new);
}
