#include "fillit.h"

int read_in(int fd)
{
	char **buf;
	char *type;
	char *type_string;
	int order;

	order = 65;
	if (!(*buf = (char *)malloc(sizeof(char) * TET_SIZE)))
		return (0);
	while (read(fd, *buf, TET_SIZE) > 0)
	{
		if (((check_tet(buf)) != 1) && ((check_tet2(buf)) != 1))			//ensures that the tetrimino is valid, if not
		{																	//function ends
			ft_putstr("error\n");
			exit (fd); 
			return (0);
		}
		else																//tetrimino is valid from here down
		{
			type_string = tet_string(buf, type_string);
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
		ft_bzero(type_string, TET_SIZE);
	}
	return (1);
}

char *tet_string(char **buf, char *type_string)
{
	int hash_count;

	hash_count = 4;
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
	return (type_string);
}
