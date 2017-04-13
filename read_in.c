#include "fillit.h"

void	clear_stuff(char *buf, char *type_string, char *final_string)
{
	ft_bzero(buf, sizeof(char) * ft_strlen(buf));
	ft_bzero(type_string, sizeof(char) * ft_strlen(type_string));
	ft_bzero(final_string, sizeof(char) * ft_strlen(final_string));
}

/*
 **  Reads the tetrimino from the fd to the buffer,
 **  ensures that it's valid, determines the tetrimino type
 **  and the order
 */

t_lst *read_in(int fd)
{
	READ_VARS;
	t_lst *list;

	order = 'A';
	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	if (!(list->current = (t_tet *)malloc(sizeof(t_tet))))
		return (0);
	if (!(list->head = (t_tet *)malloc(sizeof(t_tet))))
		return (0);
	if (!(buf = (char *)malloc(sizeof(char))))
		return (0);
	while (read(fd, (void *)buf, TET_SIZE) > 0)
	{
		if (!(check_tet(buf)) || !(check_tet2(buf)) || !(check_tet3(buf)))
		{
			ft_putstr("error\n");
			exit (fd);
		}
		if (process_string(fd, buf, list, order))
			order++;
		else
			return (0);
	}
	return (list);
}

int	process_string(int fd, void *buf, t_lst *list, char order)
{	
	char *type_string;
	char *final_string;
	t_type *save;

	create_typelist();
	if(!(final_string = (char *)malloc(sizeof(char))))
		return (0);
	if(!(type_string = (char *)malloc(sizeof(char))))
		return (0);
	type_string = tet_string(buf);
	final_string = remove_newlines(type_string);
	if ((save = tet_types(final_string)) == NULL)
	{
		ft_putstr("error\n");
		exit (fd);
	}
	to_struct(list, save, order);
	clear_stuff(buf, type_string, final_string);
	free(buf);
	return (1);
}

/*
**  Puts type and order into a struct
*/

void to_struct(t_lst *list, t_type *type, char order)
{
	if (order == 'A')
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
	if (!(type_string = (char *)malloc(sizeof(char) * ft_strlen(buf))))
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
	if (!(final_string = (char *)malloc(sizeof(char) * ft_strlen(type_string))))
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