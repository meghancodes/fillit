#include "fillit.h"

int		main(int argc, char **argv)
{
	t_lst	*list;
	t_map	*map;
	int		size;
	int		solved;
	
	solved = 0;
	if (argc == 2)
    {
        int fd;
        
        fd = open(argv[1], O_RDONLY);
        if (fd > 0)
            list = read_in(open(argv[1], O_RDONLY));
		if (!list)
			return (0);
		size = ceil_sqrt(list->size);
		map = new_map(size);
		list->current = list->head;
		while (!solve(list, map) && list->current != NULL)
		{
			list->current = list->head;
			map = new_map(size++);
		}
        print_map(map);
    }
	free_map(map);
	return (0);
}
