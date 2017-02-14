#include "fillit.h"
void to_struct(t_lst *list, char *type, char order);

/*
**  Reads the tetrimino from the fd to the buffer,
**  ensures that it's valid, determines the tetrimino type
**  and the order
*/

inint read_in(int fd)
{
	READ_VARS;
	t_lst	*list;

	order = 65;
	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	if (!(buf = (char *)malloc(sizeof(char))))
		return (0);
	while (read(fd, (void *)buf, TET_SIZE) > 0)
	{	
		if (!(check_tet(buf)) || !(check_tet2(buf)) || !(check_tet3(buf)) || !(check_tet4(buf)))			
		{																	
			ft_putstr("error\n");
			exit (fd); 
			return (0);
		}
		type_string = tet_string(buf);
		final_string = remove_newlines(type_string);
		type = find_tet_type(final_string);
		to_struct(list, type, order);
	 	order++;
	// 	ft_bzero(buf, TET_SIZE);
	// 	ft_bzero(type_string, TET_SIZE);
	}
	return (1);
}

/*
**  Puts type and order into a struct
*/

void to_struct(t_lst *list, char *type, char order)
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
**  (trimmed and with '\n's)
*/

char *tet_string(char *buf)
{
	char *type_string;
	int hash_count;
	int index;
	int index2;

	index = 0;
	index2 = 0;
	if (!(type_string = (char *)malloc(sizeof(char) * strlen(buf))))
		return (NULL);
	hash_count = 4;
	while (buf[index] != '\0')
	{
		if (buf[index] == '#')
		{	
			while (hash_count >= 1)									
			{
				if (buf[index] == '#')
					hash_count--;
				type_string[index2++] = buf[index++];
			}
			type_string[index2] = '\0';
		}
		index++;
	}
	return (type_string);
}

/*
**  Removes newlines from the trimmed string
*/

char *remove_newlines(char *type_string)
{
	char *final_string;
	int index;
	int index2;

	index = 0;
	index2 = 0;
	if (!(final_string = (char *)malloc(sizeof(char) * strlen(type_string))))
		return (NULL);
	while (type_string[index] != '\0')
	{
		if (type_string[index] == '\n')
			index++;
		final_string[index2] = type_string[index];
		index++;
		index2++;
	}
	final_string[index2] = '\0';
	return (final_string);
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
