#include "fillit.h"

int		valid_set(t_tet *node, t_map *map)
{

	return (0);
}

void	set_tet(t_tet *node, t_map *map, int x, int y)
{
	node->x = x;
	node->y = y;
	map->arr[x][y] = 1; //need to set the rest of the shape to 1
}

t_types	convert_to_ttypes(char *type)
{
	if (type = "o")
		t_types = 
	if (type = "t1")
		t_types = 
	if (type = "t2")
		t_types = 
	if (type = "t3")
		t_types = 
	if (type = "t4")
		t_types = 
	if (type = "i")
		t_types = 
	if (type = "i2")
		t_types = 
	if (type = "j")
		t_types = 
	if (type = "j1")
		t_types = 
	if (type = "j2")
		t_types = 
	if (type = "j3")
		t_types = 
	else
		return (NULL);
}

t_types	convert_to_ttypes2(char *type)
{
	if (type = "j4")
		t_types = 
	if (type = "l")
		t_types = 
	if (type = "l2")
		t_types = 
	if (type = "l3")
		t_types = 
	if (type = "l4")
		t_types = 
	if (type = "z")
		t_types = 
	if (type = "z2")
		t_types = 
	if (type = "z3")
		t_types = 
	if (type = "z4")
		t_types = 
	else
		return (NULL);
}

void	get_tets(t_types , char *types, char order, int x, int y)
{
	//t_type is holding the confirmed type
	//compare this type to t_types struct
	//order is holding the letter
	int order;

	if (convert_to_ttypes(types) != NULL)
		t_types = convert_to_ttypes(types);
	else if (convert_to_ttypes2(types) != NULL)
		t_types = convert_to_ttypes2(types);
	//order = call from function
	
	store_tets() //send info to store_tets which will hold each struct
}

void store_tets()
{

}
