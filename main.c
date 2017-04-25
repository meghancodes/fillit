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

char	*alloc_buf(void)
{
	char *buf;
	
	if (!(buf = (char *)malloc(sizeof(char))))
		return (0);
	return (buf);
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
	map = NULL;
	if (argc == 2)
    {
        int fd;
        
        fd = open(argv[1], O_RDONLY);
		buf = alloc_buf();
		if (!buf)
			return (0);
        if (fd > 0)
            list = read_in(open(argv[1], O_RDONLY), 'A', list, buf);
		if (!list->size)
			error_message();
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
