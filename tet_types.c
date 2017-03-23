#include "fillit.h"

static t_types *types;
static char *shapes[19];
static char *names[] = {"O1", "T1", "T2", "T3", "T4", "I1", "I2", "J1", "J2", "J3", "J4", "L1", "L2", "L3", "L4", "Z1", "Z2", "S1", "S2"};

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

/*
 ** Sets the height and width of a tet
 */

void		tet_size(t_tet *tet)
{
	int lines;
	int max_x;
	int max_y;
	int i;
	
	max_x = 0;
	i = 0;
	lines = check_shape(tet->type);
	max_y = lines;
	while (tet->type->shape[i] != '\0')
	{
		if (lines == 4)
		{
			max_x++;
			lines = 0;
		}
		if (tet->type->shape[i] == '#')
		{
			if ((lines % 4) > max_y)
				max_y = (lines % 4);
		}
		i++;
		lines++;
	}
	tet->h = max_x;
	tet->w = max_y;
}