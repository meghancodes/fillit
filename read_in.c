#include "fillit.h"

/*
 **  Reads the tetrimino from the fd to the buffer,
 **  ensures that it's valid, determines the tetrimino type
 **  and the order
 */

t_lst *read_in(int fd, char order, t_lst *list, char *buf)
{	
	if (read(fd, (void *)buf, TET_SIZE) == 0)
		return (list);
	else
	{
		if (!(check_tet(buf)) || !(check_tet2(buf)) || !(check_tet3(buf))
			|| (!first_check(buf)))
			error_message(fd);
		if (process_string(fd, buf, list, order))
			order++;
		else
			return (0);
	}
	return (read_in(fd, order, list, buf));
}

int first_check(char *buf)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '.')
			c++;
		i++;
	}
	if (c != 12)
		return (0);
	return (1);
}

int	process_string(int fd, void *buf, t_lst *list, char order)
{	
	t_type *save;

	create_typelist();
	if ((save = tet_types(remove_newlines(tet_string(buf)))) == NULL)
	{
		error_message(fd);
		return (0);
	}
	to_struct(list, save, order);
	ft_bzero(buf, sizeof(char) * ft_strlen(buf));
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
	free(type_string);
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
	free(final_string);
	return (final_string);
}