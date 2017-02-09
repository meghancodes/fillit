#include "fillit.h"

int main (int argc, char *argv[])
{
	int	result;

	if (argc != 2)
	{
		ft_putstr("usage: fillit_file\n");
		return (-1);
	}

	if ((result = (read_in(open(argv[1], O_RDONLY)))) == 0)
	{
		ft_putstr("error\n");
		return (-1);
	}

	// close (argv[1]);

	return (0);
}
