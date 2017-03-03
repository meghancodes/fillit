#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
    {
        int fd;
        
        fd = open(argv[1], O_RDONLY);
        if (fd > 0)
            read_in(open(argv[1], O_RDONLY));
    }
	return (0);
}
