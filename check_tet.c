#include "fillit.h"
#define T(tet, i) (tet[i - 5] == '#' || tet[i- 1] == '#' || tet[i + 1] == '#' || tet[i + 5] == '#')

/*
**  Ensures that every character is a '.' '#' or '\n'
*/

int	check_tet(char *tet)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while ((ssize_t)index < ft_strlen(tet))
	{
		if (tet[index] == '.')
			count++;
		else if (tet[index] == '#')
			count++;
		else if (tet[index] == '\n')
			count++;
		else
			return (0);
		index++;
	}
	return (1);
}

/*
**  Ensures that there are 4 '#'s and that every '#' touches
**  at least one other one
*/

int	check_tet2(char *tet)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tet[i] != '\0')
	{
		if (tet[i] == '#')
		{
			if (T(tet, i))
				count++;
			else
				return (0);
		}
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

/*
**  Ensures that '\n's appear at the right places
*/

int	check_tet3(char *tet)
{
	char **arr;
	int	count;

	count = 0;
	arr = ft_strsplit2(tet, '\n');
	if (ft_strlen(tet) > 21)
		return (0);
	while (*arr != '\0')
	{
		if (ft_strlen(*arr++) < 5 && count < 2)
			return (0);
		count++;
	}
	if (count == 4 || count == 5)
		return (count);
	return (0);
}

/*
**  Checks final_string to make sure there are no more than
**  3 dots between each hash
*/

int	check_tet4(char *final_string)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (final_string[i] != '\0')
	{
		if (final_string[i] == '.')
			count++;
		if (count > 2)
			return (0);
		i++;
		count = 0;
	}
	return (1);
}
