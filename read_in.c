#include "fillit.h"

/*
**  Reads the tetrimino from the fd to the buffer,
**  ensures that it's valid, determines the tetrimino type
**  and the order
*/

int read_in(int fd)
{
	READ_VARS;
	int x;
	int y;

	x = 0;
	y = 0;
	order = 65;
	if (!(*buf = (char *)malloc(sizeof(char) * TET_SIZE)))
		return (0);
	while (read(fd, (void *)*buf, TET_SIZE) > 0)
	{
		if (((check_tet(buf)) != 1) && ((check_tet2(buf)) != 1))			
		{																	
			ft_putstr("error\n");
			exit (fd); 
			return (0);
		}
		else																
		{
			type_string = tet_string(buf, type_string);
			type = find_tet_type(type_string);
			if (order == 65)
				current = head = new_tet(type, order, x, y);
			else
				current = current->next = new_tet(type, order, x, y);
			order++;
		}
		ft_bzero(buf, TET_SIZE);
		ft_bzero(type_string, TET_SIZE);
	}
	begin->next = NULL;
	return (1);
}

/*
**  Puts type and order into a struct
*/

/*void to_struct(void)
{
	t_tet *begin;
	t_tet *current;

	while (order = 65)
		begin = newtet(type, order, x, y);
	while (order = 66)
	

} */

/*
**  Defines the tetrimino type as a string
*/

char *tet_string(char **buf)
{
	char *type_string;
	int hash_count;

	hash_count = 4;
	while (*buf != '\0')
	{
		if (**buf == '#')
		{	
			while (hash_count >= 1)									
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

/*
**  Compares and confirms the tetrimino type
*/

char *find_tet_type(*type_string)
{
	char *type;

	if (ot_tet_types(type_string) != 0)								
		type = ot_tet_types(type_string);
	else if (ij_tet_types(type_string) != 0)
		type = ij_tet_types(type_string);
	else if (l_tet_types(type_string) != 0)
		type = l_tet_types(type_string);
	else if (zs_tet_types(type_string) != 0)
		type = zs_tet_types(type_string);
	return (type);
}
