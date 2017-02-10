#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		read_in(open(argv[1], O_RDONLY));
	return (0);
}
