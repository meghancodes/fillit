#include "fillit.h"

char *ot_tet_types(char *type_string)
{
	char *o = "##..##";
	char *t = "###..#";
	char *t2 = "#...##..#";
	char *t3 = "#..##...#";
	char *t4 = "#..###";

	if (ft_strcmp(type_string, o) == 0)
		return (o);
	if (ft_strcmp(type_string, t) == 0)
		return (t);
	if (ft_strcmp(type_string, t2) == 0)
		return (t2);
	if (ft_strcmp(type_string, t3) == 0)
		return (t3);
	if (ft_strcmp(type_string, t4) == 0)
		return (t4);
	else
		return (0);
}

char *il_tet_types(char *type_string)
{
	char *i = "#...#...#...#";
	char *i2 = "####";
	char *l = "#...#...##";
	char *l2 = "##..#...#";

	if (ft_strcmp(type_string, i) == 0)
		return (i);
	if (ft_strcmp(type_string, i2) == 0)
		return (i2);
	if (ft_strcmp(type_string, l) == 0)
		return (l);
	if (ft_strcmp(type_string, l2) == 0)
		return (l2);
	else
		return (0);
}

char *l_tet_types(char *type_string)
{
	char *l3 = "###.#";
	char *l4 = "#...###";
	char *l5 = "#...#..##";
	char *l6 = "##...#...#";
	char *l7 = "#.###";
	char *l8 = "###...#";

	if (ft_strcmp(type_string, l3) == 0)
		return (l3);
	if (ft_strcmp(type_string, l4) == 0)
		return (l4);
	if (ft_strcmp(type_string, l5) == 0)
		return (l5);
	if (ft_strcmp(type_string, l6) == 0)
		return (l6);
	if (ft_strcmp(type_string, l7) == 0)
		return (l7);
	if (ft_strcmp(type_string, l8) == 0)
		return (l8);
	else
		return (0);
}

char *z_tet_types(char *type_string)
{
	char *z = "##...##";
	char *z2 = "#..##..#";
	char *z3 = "#...##...#";
	char *z4 = "##.##";

	if (ft_strcmp(type_string, z) == 0)
		return (z);
	if (ft_strcmp(type_string, z2) == 0)
		return (z2);
	if (ft_strcmp(type_string, z3) == 0)
		return (z3);
	if (ft_strcmp(type_string, z4) == 0)
		return (z4);
	else
		return (0);
}
