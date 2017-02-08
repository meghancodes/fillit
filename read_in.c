#include "fillit.h"
void to_struct(t_list *list, char *type, char order);

/*
**  Reads the tetrimino from the fd to the buffer,
**  ensures that it's valid, determines the tetrimino type
**  and the order
*/

int read_in(int fd)
{
	READ_VARS;
	t_list	*list;

	order = 65;
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!(buf = (char **)malloc(sizeof(char *))))
		return (0);
	else if (!(*buf = (char *)malloc(sizeof(char) * TET_SIZE)))
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
			type_string = tet_string(buf);
			type = find_tet_type(type_string);
			to_struct(list, type, order);
			order++;
		}
		ft_bzero(buf, TET_SIZE);
		ft_bzero(type_string, TET_SIZE);
	}
	return (1);
}

/*
**  Puts type and order into a struct
*/

void to_struct(t_list *list, char *type, char order)
{
	if (order == 65)
	{
		list->size = 1;
		list->head = new_tet(type, order, 0, 0);
		list->current = list->head;
	}
	else
	{
		list->size = list->size + 1;
		list->current->next = new_tet(type, order, 0, 0);
		list->current = list->current->next;
	}
}

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

char *find_tet_type(char *type_string)
{
	char *type;

	type = NULL;
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
