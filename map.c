#include "fillit.h"

t_map	*new_map(int size)
{
	t_map *new;

	new = (t_map*)malloc(sizeof(t_map));
	if (new != NULL)
	{
		new->size = size;
		new->tets = NULL;
		return (new);
	}
	return (NULL);
}

void	free_map(t_map *map)
{
	//Do this with free or libft...
}
