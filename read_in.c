#include "fillit.h"

void write_error(void) //change to usage statement
{
	char *error_string;
	int index;

	error_string = "error\n";
	index = 0;
	while (error_string != '\0')
	{
		ft_putchar(error_string[index]);
		index++;
	}
}

int read_in(int fd)
{
	char **buf;
	char *type;
	char *type_string;
	int order;
	int hash_count;

	order = 65;
	hash_count = 4;
	if (!(*buf = (char *)malloc(sizeof(char) * TET_SIZE)))
		return (0);
	// if (!(type_string = (char *)malloc(sizeof(char) * TET_SIZE)))
	// 	return (0);
	while (read(fd, *buf, TET_SIZE) > 0)
	{
		if (((check_tet(*buf)) != 1) && ((check_tet2(*buf)) != 1))			//ensures that the tetrimino is valid, if not
		{																	//function ends
			write_error();
			exit (fd); 
			return (0);
		}
		else																//tetrimino is valid from here down
		{
			while (*buf != '\0')
			{
				if (**buf == '#')
				{	
					while (hash_count >= 1)									//determines the tet shape as a string
					{
						if (**buf == '#')
							hash_count--;
						type_string = *buf;
						buf++;
						type_string++;
					}
				}
				buf++;
			}
			if (ot_tet_types(type_string) != 0)								//type is determined here
				type = ot_tet_types(type_string);
			else if (ij_tet_types(type_string) != 0)
				type = ij_tet_types(type_string);
			else if (l_tet_types(type_string) != 0)
				type = l_tet_types(type_string);
			else if (z_tet_types(type_string) != 0)
				type = z_tet_types(type_string);
			order = order;													//order is determined here
			order++;
		}
		ft_bzero(buf, TET_SIZE);
	}
}
