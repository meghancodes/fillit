#include "fillit.h"

/*
**  Ensures that every character is a '.' '#' or '\n'
*/

int check_tet(char *tet)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while ((size_t)index < ft_strlen(tet))
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

int check_tet2(char *tet)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tet[i] != '\0')
	{
		if(tet[i] == '#')
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
**  Ensures that '\n's appear at the right places and that there are exactly 5
*/

int check_tet3(char *tet)
{
	int index;
	int	count;

	index = 0;
	count = 0;
	while (tet[index] != '\0')
	{
		if (tet[index] == '\n')
			count++;
		if (tet[4] != '\n' || tet[9] != '\n' || tet[14] != '\n' || tet[19] != '\n')
			return (0);
		index++;
	}
	if (count == 4 || count == 5)
		return (1);
	return (0);
}

/*
**  Checks final_string to make sure there are no more than 3 dots between each hash
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
