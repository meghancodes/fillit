#include "fillit.h"

//Use to find the smallest map possible to start with
int		ceil_sqrt(int tet_num)
{
	int	size;

	size = 2;
	while ((size * size) < tet_num)
		size++;
	return (size);
}

void	zero_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i++ < map->size)
	{
		while (j++ < map->size)
			map->arr[i][j] = 0;
		j = 0;
	}
}

t_map	*new_map(int size)
{
	t_map *new;

	new = (t_map*)malloc(sizeof(t_map));
	if (new)
	{
		new->size = size;
		new->tets = NULL;
		new->arr = (int**)malloc(sizeof(int*) * size);
		if (new->arr)
		{
			zero_map(new);
			return (new);
		}
	}
	return (NULL);
}

void	free_map(t_map *map)
{
	//Do this with free or libft...
}
