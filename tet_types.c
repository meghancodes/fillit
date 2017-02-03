#include "fillit.h"

/*
**  Compares the inputted string to each tetrimino type
*/

char *ot_tet_types(char *type_string)
{
	char *o = "##..##";
	char *t = "###..#"; 
	char *t2 = "#...##..#";
	char *t3 = "#..##...#";
	char *t4 = "#..###";

	if (ft_strcmp(type_string, o) == 0)
		return ("o");
	else if (ft_strcmp(type_string, t) == 0)
		return ("t1");
	else if (ft_strcmp(type_string, t2) == 0)
		return ("t2");
	else if (ft_strcmp(type_string, t3) == 0)
		return ("t3");
	else if (ft_strcmp(type_string, t4) == 0)
		return ("t4");
	else
		return (NULL);
}

char *ij_tet_types(char *type_string)
{
	char *i = "#...#...#...#";
	char *i2 = "####";
	char *j = "#...#..##"; //need at least two dots in front to form the shape --> ..#...#..##
	char *j2 = "##..#...#";
	char *j3 = "#...###";
	char *j4 = "###...#";

	if (ft_strcmp(type_string, i) == 0)
		return ("i");
	else if (ft_strcmp(type_string, i2) == 0)
		return ("i2");
	else if (ft_strcmp(type_string, j) == 0)
		return ("j");
	else if (ft_strcmp(type_string, j2) == 0)
		return ("j2");
	else if (ft_strcmp(type_string, j3) == 0)
		return ("j3");
	else if (ft_strcmp(type_string, j4) == 0)
		return ("j4");
	else
		return (NULL);
}

char *l_tet_types(char *type_string)
{
	char *l = "#...#...##";
	char *l2 = "###.#";
	char *l3 = "##...#...#";
	char *l4 = "#.###"; //need at least two dots in front to form the shape --> ..#.###

	if (ft_strcmp(type_string, l3) == 0)
		return ("l");
	else if (ft_strcmp(type_string, l4) == 0)
		return ("l2");
	else if (ft_strcmp(type_string, l5) == 0)
		return ("l3");
	else if (ft_strcmp(type_string, l6) == 0)
		return ("l4");
	else
		return (NULL);
}

char *z_tet_types(char *type_string)
{
	char *z = "##...##";
	char *z2 = "#..##..#";
	char *z3 = "#...##...#";
	char *z4 = "##.##";

	if (ft_strcmp(type_string, z) == 0)
		return ("z1");
	else if (ft_strcmp(type_string, z2) == 0)
		return ("z2");
	else if (ft_strcmp(type_string, z3) == 0)
		return ("z3");
	else if (ft_strcmp(type_string, z4) == 0)
		return ("z4");
	else
		return (NULL);
}
