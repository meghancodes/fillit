#include "fillit.h"

// void		print_type(t_tet *tet)
// {
// 	ft_putnbr(tet->type[1][1]);
// /*	int i;
// 	int j;
//
// 	i = 0;
// 	while (i++ < 4)
// 	{
// 		j = 0;
// 		while (j++ < 2)
// 			ft_putnbr(tet->type[i][j]);
// 	} */
// }

t_tet		*new_tet(int **type, char order, int x, int y)
{
	t_tet	*new;
	int		i;

	new = (t_tet*)malloc(sizeof(t_tet));
	if (new)
	{
		i = 0;
		new->type = (int **)malloc(sizeof(int *) * 4);
		while (i++ < 4)
			new->type[i] = (int *)malloc(sizeof(int) * 4);
		if (!new->type)
			return (NULL);
		new->type = type;
		new->order = order;
		new->x = x;
		new->y = y;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
