#include "fillit.h"

void	error_message(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	free_list(t_lst *list)
{
	list->current = list->head;
	while (list->current)
	{
		free(list->current);
		list->current = list->current->next;
	}
	list->current = NULL;
	free(list);
	list = NULL;
}

int		alloc_list(t_lst **list)
{
	if (!(*list = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	if (!((*list)->current = (t_tet *)malloc(sizeof(t_tet))))
		return (0);
	if (!((*list)->head = (t_tet *)malloc(sizeof(t_tet))))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_lst	*list;
	t_map	*map;
	int		size;
	int		solved;
	int		fd;

	solved = 0;
	list = NULL;
	alloc_list(&list);
	map = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
			list = read_in(fd, 'A', list, NULL);
		if (!list->size)
			error_message();
		size = ceil_sqrt(list->size * 4);
		map = new_map(size);
		list->current = list->head;
		while (!solve(list->head, map) && list->current != NULL)
		{
			list->current = list->head;
			map = new_map(size++);
		}
		print_map(map);
		close(fd);
	}
	free_map(map);
	free_list(list);
	return (0);
}
