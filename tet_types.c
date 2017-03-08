#include "fillit.h"

static t_types *types;
static char *shapes[19];
static char *names[] = {"O1", "T1", "T2", "T3", "T4", "I1", "I2", "J1", "J2", "J3", "J4", "L1", "L2", "L3", "L4", "Z1", "Z2", "S1", "S2"};

//static int coords_list[19][4][2];
/*
** Order is 01, T1, T2, T3, T4, I1, I2, J1, J2, J3, J4, L1, L2, L3, L3, Z1, Z2
** S1, S2
*/
static void init_shapes(void)
{
	shapes[0] = "##..##"; //O1
	shapes[1] = "###..#"; //T1
	shapes[2] = "#..##...#"; //T2 needs one dot before
	shapes[3] = "#..###"; //T3 needs one dot before
	shapes[4] = "#...##..#"; //T4
	shapes[5] = "#...#...#...#"; //I1
	shapes[6] = "####"; //I2
	shapes[7] = "#...#..##"; //J1 needs one dot before
	shapes[8] = "#...###"; //J2
	shapes[9] = "##..#...#"; //J3
	shapes[10] = "###...#"; //J4
	shapes[11] = "#...#...##"; //L1
	shapes[12] = "###.#"; //L2
	shapes[13] = "##...#...#"; //L3
	shapes[14] = "#.###"; // L4 needs two dots before
	shapes[15] = "##...##"; //Z1
	shapes[16] = "#..##..#"; // Z2 needs one dot before
	shapes[17] = "##.##"; // S1 needs one dot before
	shapes[18] = "#...##...#"; //S2
}

/*static void init_coords(void)
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
			{{0,0}, {0,1}, {0,2}, {1,2}}, //L1
			{{0,0}, {0,1}, {1,1}, {1,2}},
			{{0,0}, {1,-1}, {1,0}, {2,-1}},
			{{0,0}, {0,1}, {1,-1}, {1,0}},
			{{0,0}, {1,0}, {1,1}, {2,1}}};
	ft_memcpy(coords_list, coords_2, sizeof(coords_2));
} */

// Creates a new type struct, just need to do this once
t_type	*new_type(char *name, char *s)
{
	t_type	*new;
	int		i;

	new = malloc(sizeof(t_type));
	if (!new)
		return (NULL);
	i = 0;
	new->shape = (char *)malloc(sizeof(char) * ft_strlen(s));
	if (!new->shape)
		return (NULL);
	new->shape = s;
	new->name = (char *)malloc(sizeof(char) * 2);
	if (!new->name)
		return (NULL);
	new->name = name;
	new->next = NULL;
	return (new);
}

//Creates the linked list of types that we'll cycle through to identify tet types
void	create_typelist(void)
{
	int i;

	types = malloc(sizeof(t_types));
	if (!types)
		return ;
	types->size = 19;
//	init_coords();
	init_shapes();
	i = 1;
	types->head = new_type(names[0], shapes[0]);
	types->current = types->head;
	while (i < 19)
	{
		types->current->next = new_type(names[i], shapes[i]);
		types->current = types->current->next;
		i++;
	}
}


/*
**  Compares the inputted string to each tetrimino type
*/
t_type *tet_types(char *final_string)
{
	types->current = types->head;
	while (types->current != NULL)
	{
		if (ft_strcmp(final_string, types->current->shape) == 0)
			return (types->current);
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
