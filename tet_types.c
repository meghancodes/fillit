#include "fillit.h"

static t_types *types;
static char *shapes[19];
static int coords[19][4][2];
/*
** Order is 01, T1, T2, T3, T4, I1, I2, J1, J2, J3, J4, L1, L2, L3, L3, Z1, Z2
** S1, S2
*/
static void init_shapes(void)
{
	shapes[0] = "##..##";
	shapes[1] = "###..#";
	shapes[2] = "#...##..#";
	shapes[3] = "#..##...#";
	shapes[4] = "#..###";
	shapes[5] = "#...#...#...#";
	shapes[6] = "####";
	shapes[7] = "#...#..##";
	shapes[8] = "##..#...#";
	shapes[9] = "#...###";
	shapes[10] = "###...#";
	shapes[11] = "#...#...##";
	shapes[12] = "###.#";
	shapes[13] = "##...#...#";
	shapes[14] = "#.###";
	shapes[15] = "##...##";
	shapes[16] = "#..##..#";
	shapes[17] = "##.##";
	shapes[18] = "#...##...#";
}

static void init_coords(void)
{
	int coords_2[19][4][2] = {{{0,0}, {0,1}, {1,0}, {1,1}},
			{{0,0}, {0,1}, {0,2}, {1,1}},
			{{0,0}, {1,-1}, {1,0}, {2,0}},
			{{0,0}, {1,-1}, {1,0}, {1,1}},
			{{0,0}, {0,1}, {1,1}, {2,0}},
			{{0,0}, {1,0}, {2,0}, {3,0}},
			{{0,0}, {0,1}, {0,2}, {0,3}},
			{{0,0}, {1,0}, {2,0}, {2,1}},
			{{0,0}, {0,1}, {0,2}, {1,0}},
			{{0,0}, {0,1}, {1,1}, {2,1}},
			{{0,0}, {1,-2}, {1,-1}, {1,0}},
			{{0,0}, {1,0}, {2,-1}, {2,0}},
			{{0,0}, {1,0}, {1,1}, {1,2}},
			{{0,0}, {0,1}, {1,0}, {2,0}},
			{{0,0}, {0,1}, {0,2}, {1,2}},
			{{0,0}, {0,1}, {1,1}, {1,2}},
			{{0,0}, {1,-1}, {1,0}, {2,-1}},
			{{0,0}, {0,1}, {1,-1}, {1,0}},
			{{0,0}, {1,0}, {1,1}, {2,1}}};
	ft_memcpy((void *)coords, (const void*)coords_2, sizeof(coords_2));
}

// Creates a new type struct, just need to do this once
t_type	*new_type(int c[4][2], char *s)
{
	t_type	*new;
	int		i;
	int		j;

	new = malloc(sizeof(t_type));
	if (!new)
		return (NULL);
	new->coords = (int **)malloc(sizeof(char *) * 4);
	if (!new->coords)
		return (0);
	i = 0;
	while (i++ < 4)
	{
		j = 0;
		while (j++ < 2)
			new->coords[i][j] = c[i][j];
	}
	new->shape = (char *)malloc(sizeof(char) * ft_strlen(s));
	if (!new->shape)
		return (NULL);
	new->shape = s;
	new->next = NULL;
	return (new);
}

//Creates the linked list of types that we'll cycle through to identify tet types
int	create_typelist(void)
{
	int i;

	types = malloc(sizeof(t_types));
	if (!types)
		return (0);
	types->size = 19;
	init_coords();
	init_shapes();
	i = 1;
	types->head = new_type(coords[0], shapes[0]);
	types->current = types->head;
	while (i++ < 19)
	{
		types->current = new_type(coords[i], shapes[i]);
		types->current = types->current->next;
	}
	return (1);
}


/*
**  Compares the inputted string to each tetrimino type
*/
int **tet_types(char *type_string)
{
	types->current = types->head;
	while (types->current != NULL)
	{
		if (ft_strcmp(type_string, types->current->shape) == 0)
			return (types->current->coords);
		types->current = types->current->next;
	}
	return (NULL);
}
//
// int **ot_tet_types(char *type_string)
// {
//
//
// 	if (ft_strcmp(type_string, O1) == 0)
// 		return (types.O1);
// 	else if (ft_strcmp(type_string, T1) == 0)
// 		return (types.T1);
// 	else if (ft_strcmp(type_string, T2) == 0)
// 		return (types.T2);
// 	else if (ft_strcmp(type_string, T3) == 0)
// 		return (types.T3);
// 	else if (ft_strcmp(type_string, T4) == 0)
// 		return (types.T4);
// 	else
// 		return (NULL);
// }
//
// int **ij_tet_types(char *type_string)
// {
//
//
// 	if (ft_strcmp(type_string, I1) == 0)
// 		return (types.I1);
// 	else if (ft_strcmp(type_string, I2) == 0)
// 		return (types.I2);
// 	else if (ft_strcmp(type_string, J1) == 0)
// 		return (types.J1);
// 	else if (ft_strcmp(type_string, J2) == 0)
// 		return (types.J2);
// 	else if (ft_strcmp(type_string, J3) == 0)
// 		return (types.J3);
// 	else if (ft_strcmp(type_string, J4) == 0)
// 		return (types.J4);
// 	else
// 		return (NULL);
// }
//
// int **l_tet_types(char *type_string)
// {
//
// 	if (ft_strcmp(type_string, L1) == 0)
// 		return (types.L1);
// 	else if (ft_strcmp(type_string, L2) == 0)
// 		return (types.L2);
// 	else if (ft_strcmp(type_string, L3) == 0)
// 		return (types.L3);
// 	else if (ft_strcmp(type_string, L4) == 0)
// 		return (types.L4);
// 	else
// 		return (NULL);
// }
//
// int **zs_tet_types(char *type_string)
// {
// 	if (ft_strcmp(type_string, Z1) == 0)
// 		return (types.Z1);
// 	else if (ft_strcmp(type_string, Z2) == 0)
// 		return (types.Z2);
// 	else if (ft_strcmp(type_string, S1) == 0)
// 		return (types.S1);
// 	else if (ft_strcmp(type_string, S2) == 0)
// 		return (types.S2);
// 	else
// 		return (NULL);
// }
