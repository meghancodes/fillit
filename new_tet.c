#include "fillit.h"

t_tet		*new_tet(t_type *type, char order, int x, int y)
{
	t_tet	*new;
	int		i;

	new = (t_tet*)malloc(sizeof(t_tet));
	if (new)
	{
		i = 0;
		new->type = type;
		if (!new->type)
			return (NULL);
		new->order = order;
		new->x = x;
		new->y = y;
		tet_size(new);
		new->next = NULL;
		return (new);
	}
	return (NULL);
}