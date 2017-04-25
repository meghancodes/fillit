#include "fillit.h"

void	error_message(int fd)
{
	ft_putstr("error\n");
	exit(fd);
}

void	free_list(t_lst *list)
{
	list->current = list->head;
	while (list->current)
	{
		free(list->current);
		list->current = list->current->next;
	}
	free(list);
}

int		main(int argc, char **argv)
{
	t_lst	*list;
	t_map	*map;
	char	*buf;
	int		size;
	int		solved;
	
	solved = 0;
	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	if (!(list->current = (t_tet *)malloc(sizeof(t_tet))))
		return (0);
	if (!(list->head = (t_tet *)malloc(sizeof(t_tet))))
		return (0);
	if (!(buf = (char *)malloc(sizeof(char))))
		return (0);
	map = NULL;
	if (argc == 2)
    {
        int fd;
        
        fd = open(argv[1], O_RDONLY);
        if (fd > 0)
            list = read_in(open(argv[1], O_RDONLY), 'A', list, buf);
		if (!list->size)
		{
			error_message(fd);
			return (0);
		}
		size = ceil_sqrt(list->size);
		map = new_map(size);
		list->current = list->head;
		while (!solve(list->head, map) && list->current != NULL)
		{
			list->current = list->head;
			map = new_map(size++);
		}
       print_map(map);
    }
	free_map(map);
	free_list(list);
	return (0);
}
