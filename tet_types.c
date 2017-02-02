#include "fillit.h"

char *ot_tet_types(char *type_string)
{
	char *o = "##..##";
	char *t = "###..#"; 
	char *t2 = "#...##..#";
	char *t3 = "#..##...#";
	char *t4 = "#..###";

	if (ft_strcmp(type_string, o) == 0)
		return ("o");
	if (ft_strcmp(type_string, t) == 0)
		return ("t1");
	if (ft_strcmp(type_string, t2) == 0)
		return ("t2");
	if (ft_strcmp(type_string, t3) == 0)
		return ("t3");
	if (ft_strcmp(type_string, t4) == 0)
		return ("t4");
	else
		return (NULL);
}

char *ij_tet_types(char *type_string)
{
	char *i = "#...#...#...#";
	char *i2 = "####";
	char *j = "#...#..##"; //J --real J -- need at least two dots in front to form the shape --> ..#...#..##
	char *j2 = "##..#...#"; //J
	char *j3 = "#...###"; //J
	char *j4 = "###...#"; //J

	if (ft_strcmp(type_string, i) == 0)
		return ("i");
	if (ft_strcmp(type_string, i2) == 0)
		return ("i2");
	if (ft_strcmp(type_string, j) == 0)
		return ("j");
	if (ft_strcmp(type_string, j2) == 0)
		return ("j2");
	if (ft_strcmp(type_string, j3) == 0)
		return ("j3");
	if (ft_strcmp(type_string, j4) == 0)
		return ("j4");
	else
		return (NULL);
}

char *l_tet_types(char *type_string)
{
	char *l = "#...#...##"; //L --real L
	char *l2 = "###.#"; //L
	char *l3 = "##...#...#"; //L
	char *l4 = "#.###"; //L -- need at least two dots in front to form the shape --> ..#.###

	if (ft_strcmp(type_string, l3) == 0)
		return ("l");
	if (ft_strcmp(type_string, l4) == 0)
		return ("l2");
	if (ft_strcmp(type_string, l5) == 0)
		return ("l3");
	if (ft_strcmp(type_string, l6) == 0)
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
	if (ft_strcmp(type_string, z2) == 0)
		return ("z2");
	if (ft_strcmp(type_string, z3) == 0)
		return ("z3");
	if (ft_strcmp(type_string, z4) == 0)
		return ("z4");
	else
		return (NULL);
}
