#include "fillit.h"

int		main(int argc, char **argv)
{
	t_lst	*tmp;
	int		size;
	
	if (argc == 2)
    {
        int fd;
        
        fd = open(argv[1], O_RDONLY);
        if (fd > 0)
            tmp = read_in(open(argv[1], O_RDONLY));
		if (!tmp)
			return (0);
		size = ceil_sqrt(tmp->size);
    }
	return (0);
}
