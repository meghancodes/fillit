#include "fillit.h"

t_tet		*new_tet(int **type, char order, int x, int y)
{
	t_tet	*new;

	new = (t_tet*)malloc(sizeof(t_tet));
	if (new)
	{
		new->type = type;
		new->order = order;
		new->x = x;
		new->y = y;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
