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

char	**to_arr(char *v_tet)
{
	char	**arr;
	int		i;
	int		j;
	int		in;

	if (!(arr = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	else if (!(*arr = (char *)malloc(sizeof(char) * 4)))
		return (0);
	i = 0;
	in = 0;
	while (i++ < 4)
	{
		j = 0;
		in++;
		while (j++ < 4)
		{
			arr[i][j] = v_tet[in++];
		}
	}
	return (arr);
}

/*
**  checks whether there are 4 '#' in the tet
**  and whether every '#' touches one other '#'
**  (ensures it's a valid tetromino)
*/

int	check_tet2(char *v_tet)
{
	int		i;
	int		j;
	int		count;
	char	**arr;

	i = 0;
	count = 0;
	arr = to_arr(v_tet);
	while (i++ < 4)
	{
		j = 0;
		while (j++ < 4)
		{
			
		}
	}
	if (count == 4)
		return (1);
	return (0);
}
