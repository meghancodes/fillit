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

void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
			ft_putchar(map->arr[i][j++]);
		map->arr[i][j] = '\0';
		ft_putchar('\n');
		i++;
	}
}

t_map	*new_map(int size)
{
	t_map *new;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->size = size;
	new->arr = (char **)malloc(sizeof(char*) * size + 5);
	if (new->arr)
	{
		int i;
		i = 0;
		while (i < size)
			new->arr[i++] = (char *)malloc(sizeof(char) * size + 5);
		zero_map(new);
		return (new);
	}
	return (NULL);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (map)
	{
		while (i < map->size)
			free(map->arr[i++]);
		free(map);
	}
}
