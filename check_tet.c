#include "fillit.h"

/*
**  checks whether input is a '.' or '#'
*/

int	check_tet(char *v_tet)
{
	TET_VARS;

	i = 0;
	tet = v_tet;
	while (i < 19)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (i != '\n')
				return (0);
		}
		else if (tet[i] != '.' || tet[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

/*
**  checks whether there are 4 '#' in the tet
**  and whether every '#' touches one other '#'
**  (ensures it's a valid tetromino)
*/

int	check_tet2(char *v_tet)
{
	TET_VARS;
	int count;
	int next_rowpos;
	int next_colpos;

	row = 0;
	count = 0;
	tet = v_tet;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			check = tet[row][column];
			next_rowpos = tet[row + 1][column];
			next_colpos = tet[row][column + 1];
			if (check == '#' && (next_rowpos == '#' || next_colpos == '#'))
				count++;
			column++;
		}
		row++;
	}
	if (count == 4)
		return (1);
	return (0);
}
