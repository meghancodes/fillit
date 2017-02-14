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
	while (index < ft_strlen(tet))
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
	int index;
	int count;
	int hash_touch;

	index = 0;
	count = 0;
	hash_touch = 0;
	while (tet[index] != '\0')
	{
		if(tet[index] == '#')
		{
			count++;
			if ((tet[index - 5]) == '#' || (tet[index - 1]) == '#' || (tet[index + 1]) == '#' || 
				(tet[index + 5]) == '#')
				hash_touch++;
			else
				return (0);
		}
		index++;
	}
	if (count != 4)
		return (0);
	return (1);
}

/*
**  Ensures that there are 5 '\n's
*/

int check_tet3(char *tet)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (tet[index] != '\0')
	{
		if (tet[index] == '\n')
			count++;
		index++;
	}
	if (count != 5)
		return (0);
	return (1);
}

/*
**  Ensures that '\n's appear at the right places 
*/

int check_tet4(char *tet)
{
	int index;

	index = 0;
	while (tet[index] != '\0')
	{
		if (tet[4] != '\n' || tet[9] != '\n' || tet[14] != '\n' || tet[19] != '\n' 
			|| tet[20] != '\n')
			return (0);
		index++;
	}
	return (1);
}
